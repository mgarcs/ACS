package cl.utfsm.samplingSystemUI;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Calendar;

import cl.utfsm.samplingSystemUI.core.DataItem;

public class FileHelper {
	
	private String filename="";
	private FileWriter file;
	private BufferedWriter writer;
	private String header;
	private int c[];
	ArrayList<ArrayList<DataItem>> data;
	
	public FileHelper(){
		data = new ArrayList<ArrayList<DataItem>>();
	}
	
	public void addSamplingSet(ArrayList<DataItem> samp){
		data.add(samp);
	}
	
	public void setHeaderFile(String header){
		this.header=header;
	}
	
	public void dumpToFile(long frequency){
		dumpToFile(frequency,0.5);
	}
	
	public String getFileName(){
		return filename;
	}
	
	public void initialize(int freq){
		filename = "samp_"+10000000L/freq+"_"+Calendar.getInstance().getTimeInMillis();
	}
	
	public void dumpToFile(long frequency, double prec){
		//long milis = Calendar.getInstance().getTimeInMillis();
		long timestamp=data.get(0).get(0).getTime();
		boolean done = false;
		frequency=10000000L/frequency;
		long w = (long) (frequency*prec);
		c=new
		int[data.size()];
		//filename = "samp_"+frequency+"_"+milis;
		openFile();
		try {
			writer.write(header+"\n");
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		while(!done){
			String line = "" + timestamp;
			for(int i=0;i<data.size();i++){
				if(c[i]==data.get(i).size()){
					line+=";";
					continue;
				}
				DataItem item = data.get(i).get(c[i]);
				if((item.getTime()>=(timestamp-w)) && (item.getTime()<=(timestamp+w))){
					line+=";"+item.getValue();
					c[i]++;
				}
				else if((item.getTime()>=(timestamp+w)) &&  
						(item.getTime()<=(timestamp+frequency-w))){
					line+=";";
					c[i]++;
				}
				else
					line+=";";
			}
			try {
				writer.write(line+"\n");
			} catch (IOException e) {
				e.printStackTrace();
			}
			/*Check if we passed over all dataItem recolected*/
			int flag=0;
			for(int i=0;i<c.length;i++){
				if(c[i]==data.get(i).size())
					flag++;
			}
			if (flag==c.length)
				done=true;
			
			timestamp+=frequency;
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private void openFile(){
		try {
			file=new FileWriter(filename);
		} catch (IOException e) {
			e.printStackTrace();
		}
		writer=new BufferedWriter(file);
	}
}
