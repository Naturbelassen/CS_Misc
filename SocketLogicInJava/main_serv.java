import java.net.*;
import java.io.*;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.Objects;
import java.util.Scanner;
import java.util.UUID;

//Server

public class main {
    public static void main(String[] args) throws IOException {
        String uuid = UUID.randomUUID().toString();
        ServerSocket serverSocket = new ServerSocket(11114);
        Socket socket = serverSocket.accept();
        System.out.println("Connected!!");
        DataInputStream ah = new DataInputStream(socket.getInputStream());
        int length = ah.readInt();
        if(length > 0){
            byte[] abcc = new byte[length];
            ah.readFully(abcc);
            String sendIt = new String(abcc, StandardCharsets.UTF_8);
            System.out.println(sendIt);
            String[] splitted = sendIt.split("\\s+");

            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            if(Objects.equals(splitted[0], "HELLO")){
                String send = "HI " + uuid + " " + "11114" + " Musterfrau";
                byte[] toSend = send.getBytes(StandardCharsets.UTF_8);
                out.writeInt(toSend.length);
                out.write(toSend);

            }else{
                String send = "Kein Hello gefunden";
                byte[] toSend = send.getBytes(StandardCharsets.UTF_8);
                out.writeInt(toSend.length);
                out.write(toSend);
            }
        }
    }
}
