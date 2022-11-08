import java.io.*;
import java.net.*;
import java.nio.charset.*;
import java.util.UUID;

//Client

public class main {
	public static void main(String[] args) throws IOException{
		String uuid = UUID.randomUUID().toString();
		Socket socket = new Socket("localhost", 11114);
		DataOutputStream out = new DataOutputStream(socket.getOutputStream());
		String jj = "HELLO " + uuid + " " + "11114" + " Mustermann";
		byte[] toByte = jj.getBytes(StandardCharsets.UTF_8);
		out.writeInt(toByte.length);
		out.write(toByte);

		DataInputStream ah = new DataInputStream(socket.getInputStream());
		int length = ah.readInt();
		if(length > 0){
			byte[] abcc = new byte[length];
			ah.readFully(abcc);
			String nn = new String(abcc, StandardCharsets.UTF_8);
			System.out.println(nn);
		}
	}
}