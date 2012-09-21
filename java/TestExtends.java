public class TestExtends extends Base
{
	@Override
	public void print()
	{
		System.out.println("print");
	}
	public void sayHello()
	{
		super.sayHello();
		System.out.println("hello, extender");
	}
	public static void main(String[] args)
	{
		Base b = new TestExtends();
		b.sayHello();
		b.print();
	}
}

abstract class Base
{
	abstract public void print();
	public void sayHello(){System.out.println("hello, Base!");}
}
