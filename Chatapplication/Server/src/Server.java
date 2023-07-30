import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Server {
    ServerSocket server=null;
    DataInputStream in=null;
    DataOutputStream out=null;
    Scanner geterminal=null;
    String toclient,fromClient;
    Server(int port)
    {
        try {
            server = new ServerSocket(port);
            System.out.println("Waiting for client....");
            Socket client=server.accept();
            System.out.println("Client connected to "+client.getLocalAddress()+" to the port "+client.getPort());
            in = new DataInputStream(client.getInputStream());
            out=new DataOutputStream(client.getOutputStream());
            geterminal=new Scanner(System.in);
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
    public void chat()
    {
        try {
            //System.out.print("You : ");
            out.writeUTF("Hi Hello!!!!");
            out.flush();
            fromClient=in.readUTF();
            System.out.println("Client : "+fromClient);
            while (!fromClient.equals("Thank You"))
            {
                System.out.print("You : ");
                toclient=geterminal.nextLine();
                out.writeUTF(toclient);
                out.flush();
                fromClient=in.readUTF();
                System.out.println("Client :"+fromClient);
            }
            out.close();
            server.close();
            in.close();
            geterminal.close();
        }
        catch (Exception error)
        {
            System.out.println(error);
        }

    }
}
