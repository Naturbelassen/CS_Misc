package superKeyword;

class B extends A{
	String b = "ByeBye";
	
	@Override
	public void show() {
		System.out.println(b);
	}
	
	public void alter() {
		super.a = "WW";
		super.show();
	}
}
