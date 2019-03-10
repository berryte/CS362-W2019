

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   //Run isValid test on url.  0 means it is valid 1 means it is invalid
   public int passFail(String url) {
	   UrlValidator urlVal = new UrlValidator(); //create url validator object
	   if(urlVal.isValid(url)) {
		   return 0;
	   }
	   else {
		   return 1;
	   }
   }

   //Print result of the isValid test and show if it passed or failed
   public void result(String url, int expected) {
	   if(passFail(url) == 0 && expected == 0) { //if url is valid and expected it to be valid
		   System.out.print("Test Passed! " + url + " is valid\n");
	   }
	   else if(passFail(url) == 1 && expected == 1){ //if url is invalid and expected it to be invalid
		   System.out.print("Test Passed! " + url + " is invalid\n");
	   }
	   else if(passFail(url) == 1 && expected == 0){ //if url is invalid and expected it to be valid
		   System.out.print("Test Failed! " + url + " should be valid\n");
	   }
	   else if(passFail(url) == 0 && expected == 1){ //if url is valid and expected it to be invalid
		   System.out.print("Test Failed! " + url + " should be invalid\n");
	   }
	   
   }

   //Perform Manual testing on isValid()
   public void testManualTest()
   {	
	   System.out.print("\nManual Testing\n\n"); //start manual testing
	   
	   String address = "https://www.google.com";
	   int i = 1;
	   System.out.print("Test " + i + ": ");
	   result(address, 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://www.google.com", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://www.google.com:80/test1?action=edit&mode=up", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://www.google.com/test1", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://www.google.com/t123?action=edit&mode=up", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://go.com:80", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://go.com/$23", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://go.au:90/test1", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://0.0.0.0:0", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://255.com:0?action=edit&mode=up", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("h3t://go.com/$23", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("ftp://www.google.com:0/t123", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("ftp://www.google.com:0/t123", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("ftp://www.google.com:0/t123", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("https://www.oregonstate.edu", 0);
	   i++;
	   
	   System.out.print("Test " + i + ": ");
	   result("://:65a/test1//file", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("://:65a/..?action=view", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("://:-1/$23", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("://1.2.3.4.:65535/test1/?action=edit&mode=up", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("oregonstate.edu", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("testing.com", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://here", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("definitely wrong", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("1.2.3.4", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://1.2.3.4", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://help.google.com", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("wrong.org", 1);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("ftp://hello.com", 0);
	   i++;
	   System.out.print("Test " + i + ": ");
	   result("http://1.2.3.4.com", 0); //worked in the other url validator
	   i++;
	   System.out.print("Test " + i + ": ");
           result("htp://hello.com", 1);
           i++;
	   System.out.print("Test " + i + ": ");
           result("http://wwww.oregonstate.edu", 1);
           i++;
           System.out.print("Test " + i + ": ");
           result("http://zzz.oregonstate.edu", 1);
           i++;


	   
	   System.out.print("\nManual Testing Completed!\n"); //end Manaul testing
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
