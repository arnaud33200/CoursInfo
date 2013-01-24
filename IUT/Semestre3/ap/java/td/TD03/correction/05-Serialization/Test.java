import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;


public class Test {
    
    public static void main(String[] args) throws IOException, ClassNotFoundException {
	People dupont = new People("Jean", "Dupont", 1960, 11, 25);
	System.out.println(dupont);
	String dataFile = "essai";
	ObjectOutputStream out = null;
        try {
            out = new ObjectOutputStream(new
					 BufferedOutputStream(new FileOutputStream(dataFile)));
            out.writeObject(dupont);
        } finally {
            out.close();
        }
        
        People dupontBis;
        ObjectInputStream in = null;
        try {
            in = new ObjectInputStream(new
				       BufferedInputStream(new FileInputStream(dataFile)));
            dupontBis = (People) in.readObject();
        } finally {
            in.close();
        } 
	System.out.println(dupontBis);
    }
    
}
