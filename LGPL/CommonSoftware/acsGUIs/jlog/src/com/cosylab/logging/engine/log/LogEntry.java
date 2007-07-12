/*
 *    ALMA - Atacama Large Millimiter Array
 *    (c) European Southern Observatory, 2002
 *    Copyright by ESO (in the framework of the ALMA collaboration)
 *    and Cosylab 2002, All rights reserved
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 2.1 of the License, or (at your option) any later version.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 *    MA 02111-1307  USA
 */
package com.cosylab.logging.engine.log;

import java.util.Date;
import java.util.Vector;

import java.text.SimpleDateFormat;
import java.text.FieldPosition;

import com.cosylab.logging.engine.log.LogTypeHelper;

/**
 * Objects of this class holds implements the ILogEntry interface
 * representing a generic log record. This class does not contain
 * any reference to XML parsers
 * 
 * @author acaproni
 */
public class LogEntry implements ILogEntry {
	
	private Date date;
	private Integer type;
	private String file;
	private Integer line;
	private String routine;
	private String host;
	private String process;
	private String context;
	private String thread;
	private String logId;
	private Integer priority;
	private String uri, stackId;
	private Integer stackLevel;
	private String logMessage;
	private String sourceObject;
	private String audience;
	private String array;
	private String antenna;
	
	// The additional data
	private  Vector<LogEntry.AdditionalData> additionalData = null;

	/**
	 * Builds a LogEntry object from the value of its fields
	 * All the fields are defined in the ILogEntry interface.
	 * 
	 * 
	 * @param milliseconds The date
	 * @param entrytype The type
	 * @param file ...
	 * @param line ...
	 * @param routine ...
	 * @param host ...
	 * @param process ...
	 * @param context ...
	 * @param thread ...
	 * @param logid ...
	 * @param priority ...
	 * @param uri ...
	 * @param stackid ...
	 * @param stacklevel ...
	 * @param logmessage ...
	 * @param srcObject ...
	 * @param audience ...
	 * @param array ...
	 * @param antenna ...
	 * @param addDatas The additional data as a Vector<String>
	 *                 The Vector contains in the even position the name 
	 *                 and in the odd the value. It can be null.
	 *                 @see LogEntryXML.getAdditionalData
	 * 
	 * @see ILogEntry
	 */
	public LogEntry(
			Long milliseconds,
			Integer entrytype,
			String file,
			Integer line,
			String routine,
			String host,
			String process,
			String context,
			String thread,
			String logid,
			Integer priority,
			String uri,
			String stackid,
			Integer stacklevel,
			String logmessage,
	        String srcObject,
	        String audience,
	        String array,
	        String antenna,
	        Vector<AdditionalData> addDatas) {
		if(null != milliseconds) {
			this.date=new Date(milliseconds);
		}
		else {
			this.date = null;
		}
		this.type=LogTypeHelper.logTypes[entrytype];
		this.file=file;
		this.line=line;
		this.routine=routine;
		this.host=host;
		this.process=process;
		this.context=context;
		this.thread=thread;
		this.logId=logid;
		this.priority=priority;
		this.uri=uri;
		this.stackId=stackid;
		this.stackLevel=stacklevel;
		this.logMessage=logmessage;
		this.sourceObject=srcObject;
		this.audience=audience;
		this.array=array;
		this.antenna=antenna;
		// Add the additional datas, if any
		if (addDatas!=null) {
			additionalData = new Vector<LogEntry.AdditionalData>();
			additionalData.addAll(addDatas);
		}
	}
	
	/**
	 * Build a LogEntry from a LogEntryXML
	 * 
	 * @param logXML The log entry
	 * @see LogEntryXML
	 */
	public LogEntry(LogEntryXML logXML) {
		for (int fieldIndex=0; fieldIndex<NUMBER_OF_FIELDS; fieldIndex++) {
			setField(fieldIndex,logXML.getField(fieldIndex));
		}
		// Add the additional datas, if any
		Vector<AdditionalData> addDatas=logXML.getAdditionalData();
		if (addDatas!=null) {
			additionalData = new Vector<LogEntry.AdditionalData>();
			additionalData.addAll(addDatas);
		}
	}

	/**
	 * @return an XML string representing this log
	 */
	public String toXMLString() {
		StringBuilder sb = new StringBuilder();

		String logType =LogTypeHelper.getLogTypeDescription(type);
		sb.append("<"+logType);
		
		for (int t=0; t<NUMBER_OF_FIELDS; t++) {
			if (t==FIELD_LOGMESSAGE || t==FIELD_ENTRYTYPE) {
				continue;
			}
			Object attrValue = getField(t);
			if (attrValue!=null) {
				if (Date.class.isInstance(attrValue)) {
					SimpleDateFormat df = new SimpleDateFormat(TIME_FORMAT);
					Date dt = (Date)attrValue;
					StringBuffer dateSB = new StringBuffer();
					java.text.FieldPosition pos = new java.text.FieldPosition(0);
					df.format(dt,dateSB,pos);
					attrValue=dateSB.toString();
				}
				String attrValStr = attrValue.toString();
				attrValStr=attrValStr.replaceAll("<","&lt;");
				attrValStr=attrValStr.replaceAll(">","&gt;");
				sb.append(" "+tagAttributes[t]+"=\""+attrValStr+"\"");
			}
		}
		
		if (type==LogTypeHelper.ENTRYTYPE_TRACE && !hasDatas()) {
			sb.append("/>");
		} else {
			sb.append(">");
			if (logMessage!=null) {
				sb.append("<![CDATA["+logMessage+"]]>");
			}
			if (hasDatas()) {
				sb.append(getXMLDatas());
			}
			sb.append("</"+logType+">");
		}
		return sb.toString();
	}
	
	/**
	 * 
	 * @return The XML representation of the additional data
	 */
	private StringBuilder getXMLDatas() {
		StringBuilder tempStr = new StringBuilder();
		if (additionalData!=null) {
			int size = additionalData.size();
			for (int t=0; t<size; t++) {
				AdditionalData temp = additionalData.get(t);
				String name = temp.getName();
				String value= temp.getValue();
				// Cleanup
				name=name.replaceAll("<","&lt;").replaceAll(">","&gt;").trim();
				value=value.replaceAll("<","&lt;").replaceAll(">","&gt;").trim();
				tempStr.append("<Data Name=\""+name+"\">");
				tempStr.append(value);
				tempStr.append("</Data>");
			}
		}
		return tempStr;
	}

	/**
	 * @return True if the log has additional data
	 */
	public boolean hasDatas() {
		if (additionalData==null) {
			return false;
		} 
		return additionalData.size()>0;
	}

	/**
	 * @param fieldIndex The index of the field of the object to get
	 * @return The object of the given index
	 */
	public Object getField(int fieldIndex) {
		switch (fieldIndex) {
			case FIELD_TIMESTAMP: {
				return date;
			}
			case FIELD_ENTRYTYPE: {
				return type;
			}
			case FIELD_SOURCEOBJECT: {
				return sourceObject;
			}
			case FIELD_AUDIENCE: {
				return audience;
			}
			case FIELD_ARRAY: {
				return array;
			}
			case FIELD_ANTENNA: {
				return antenna;
			}
			case FIELD_FILE: {
				return file;
			}
			case FIELD_LINE: {
				return line;
			}
			case FIELD_ROUTINE: {
				return routine;
			}
			case FIELD_HOST: {
				return host;
			}
			case FIELD_PROCESS: {
				return process;
			}
			case FIELD_CONTEXT: {
				return context;
			}
			case FIELD_THREAD: {
				return thread;
			}
			case FIELD_LOGID: {
				return logId;
			}
			case FIELD_PRIORITY: {
				return priority;
			}
			case FIELD_URI: {
				return uri;
			}
			case FIELD_STACKID: {
				return stackId;
			}
			case FIELD_STACKLEVEL: {
				return stackLevel;
			}
			case FIELD_LOGMESSAGE: {
				return logMessage;
			}
			default: {
				throw new IndexOutOfBoundsException("Illegal index "+fieldIndex);
			}
		}
	}
	
	/**
	 * Sets the specified field. This method is protected since the fields are not
	 * to be modified. The only time this is called is during initialization.
	 * Creation date: (11/21/2001 18:35:10)
	 * @param fieldIndex int index of the field
	 * @param value java.lang.Object value to set
	 */
	protected void setField(int fieldIndex, Object value)
	{
		switch (fieldIndex) {
			case FIELD_TIMESTAMP: {
				date=(Date)value;
				return;
			}
			case FIELD_ENTRYTYPE: {
				type=LogTypeHelper.logTypes[(Integer)value];
				return;
			}
			case FIELD_SOURCEOBJECT: {
				sourceObject=(String)value;
				return;
			}
			case FIELD_AUDIENCE: {
				audience=(String)value;
				return;
			}
			case FIELD_ARRAY: {
				array=(String)value;
				return;
			}
			case FIELD_ANTENNA: {
				antenna=(String)value;
				return;
			}
			case FIELD_FILE: {
				file=(String)value;
				return;
			}
			case FIELD_LINE: {
				line=(Integer)value;
				return;
			}
			case FIELD_ROUTINE: {
				routine=(String)value;
				return;
			}
			case FIELD_HOST: {
				host=(String)value;
				return;
			}
			case FIELD_PROCESS: {
				process=(String)value;
				return;
			}
			case FIELD_CONTEXT: {
				context=(String)value;
				return;
			}
			case FIELD_THREAD: {
				thread=(String)value;
				return;
			}
			case FIELD_LOGID: {
				logId=(String)value;
				return;
			}
			case FIELD_PRIORITY: {
				priority=(Integer)value;
				return;
			}
			case FIELD_URI: {
				uri=(String)value;
				return;
			}
			case FIELD_STACKID: {
				stackId=(String)value;
				return;
			}
			case FIELD_STACKLEVEL: {
				stackLevel=(Integer)value;
				return;
			}
			case FIELD_LOGMESSAGE: {
				logMessage=(String)value;
				return;
			}
			default: {
				throw new IndexOutOfBoundsException("Illegal index "+fieldIndex);
			}
		}

	}
	
	public void addData(String name, String value) {
		if (name==null || value==null) {
			throw new IllegalArgumentException("Parameter can't be null");
		}
		if (name.length()==0 || value.length()==0) {
			throw new IllegalArgumentException("Parameters can't be empty string");
		}
		
		if (additionalData ==null) {
			additionalData = new Vector<LogEntry.AdditionalData>();
		}
		additionalData.add(new AdditionalData(name,value));
	}
	
	/**
	 * Return a string representation of this entry
	 */
	public String toString() {
		StringBuffer sb = new StringBuffer("--- LogEntry ---\n");

		/* Attributes */
		for (int i = 0; i < NUMBER_OF_FIELDS; i++)
		{
			if (getField(i) != null) {
				sb.append(fieldNames[i] + ": ");
				if (i == FIELD_ENTRYTYPE) {
					sb.append(LogTypeHelper.getLogTypeDescription(type));
				} else if(i==FIELD_TIMESTAMP) {
					SimpleDateFormat df = new SimpleDateFormat(TIME_FORMAT);
					FieldPosition pos = new FieldPosition(0);
					df.format(date,sb,pos);
				} else {
					sb.append(getField(i));
				}
				sb.append("\n");
			}
		}
        
		/* Data(s) */
		if (additionalData != null) {
			sb.append("Datas: \n");
			for (int t=0; t<additionalData.size(); t++) {
				AdditionalData temp = additionalData.get(t);
				sb.append("\t"+temp.getName()+" : "+temp.getValue());
			}
		}

		return sb.toString();
	}
	
	/**
	 * @see ILogEntry
	 */
	public Vector<AdditionalData> getAdditionalData() {
		return additionalData;
	}
	
	/**
	 * @see ILogEntry
	 */
	public Integer getType() {
		return type;
	}

}
