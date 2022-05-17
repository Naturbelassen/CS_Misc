import java.io.*;
import java.util.*;
import java.net.*;
import java.nio.charset.StandardCharsets;

public class connect{
    public static void main(String[] args){

    try{
        Socket socket = new Socket("localhost", 5555); 
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8));
        PrintStream printStream = new PrintStream(socket.getOutputStream(), true, StandardCharsets.UTF_8);
        printStream.println("HIHOHIHO");
        String print = bufferedReader.readLine();
        System.out.println(print);  
    }catch(Exception e){
        System.out.println("ERROR");
    }
    }
}