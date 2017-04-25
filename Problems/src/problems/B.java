package problems;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

class A
{

}

public class B extends A
{
	public void getA()
	{
		System.out.println("A");
	}

	public static void main(String[] args) throws IOException
	{
		A a = new A();
		A b = new B();
		((B) a).getA(); // throws a Runtime exception - ClassCastException
		((B) b).getA();

		File file = new File("/Users/Anand/Documents/home_value.txt");

		FileWriter writer = new FileWriter(file);

		writer.write("50000 26000\n");
		for (int i = 0; i < 50000; i++)
			writer.write(i + " ");
		writer.flush();
		writer.close();
	}

}
