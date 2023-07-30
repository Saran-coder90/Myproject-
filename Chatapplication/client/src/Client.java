import java.net.*;
import java.io.*;
import java.nio.*;
public class Client {
    Socket cLient = null;
    BufferedReader getinput = null;
    DataOutputStream out = null;
    DataInputStream in = null;
    String fromServer, toServer;

    Client(String IP, int port) {
        try {
            cLient = new Socket(IP, port);
            getinput=new BufferedReader(new InputStreamReader(System.in));
            in=new DataInputStream(cLient.getInputStream());
            out=new DataOutputStream(cLient.getOutputStream());
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
    }
    public void chat()
    {
        try
        {
            fromServer=in.readUTF();
            System.out.println("Server: "+fromServer);
            while (!fromServer.equals("Busy")) {
                System.out.print("You : ");
                toServer = (String) getinput.readLine();
                out.writeUTF(toServer);
                out.flush();
                fromServer = in.readUTF();
                System.out.println("Server : " + fromServer);
            }
            out.close();
            cLient.close();
            in.close();
            getinput.close();
            /*byte[] byt=new byte[100];
            in.read(byt);
            String val =new String(byt);
            while(!val.equals("bye")){
                System.out.println("Server :"+val);
                byt=new byte[100];
                in.read(byt);
                val=new String(byt);
                //i++;
            }*/
            //}
            in.close();
            cLient.close();
        }
        catch(Exception error)
        {
            System.out.println(error);
        }
    }
}
