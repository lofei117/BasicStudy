class Test{  
   private int i=9;  
   private int j=9;  
   private String a="12345";
   private String b="12345";
  private String aa=new String("12345");
   
   public static void main(String args[]){   
     int w=9;  
     String c="12345";
     Test t=new Test();  
     
     System.out.println(t.i==t.j);//true  
     System.out.println(t.i==w);//true  
     System.out.println(t.a==t.aa);
	 System.out.println(t.a==c);
 System.out.println(t.a.equals(t.aa));


}  
  
}  

