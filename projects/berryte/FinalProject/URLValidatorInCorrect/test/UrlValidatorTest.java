package test;

import java.util.Random;
import java.util.regex.Matcher;

import finalprojectB.UrlValidator;
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
   




   /* return the result of isValid on the URL
   * return 0 if isValid finds no problems with the URL
   * return 1 otherwise */ 
   public static int resIsValid(String url, UrlValidator uvObj) {
      if (uvObj.isValid(url)) {
        return 0;
      } else {
        return 1;
      }
   } 
 
   /* show the results of the current test
   * compare the result of isValid with the expected value
   * if actual matches expected, test passes
   * otherwise, test fails */ 
   public static void showTestRes(String url, int expected, UrlValidator uvObj) {
      if (resIsValid(url, uvObj) == 0 && expected == 0) {
         System.out.print("Passed: " + url + " correctly marked valid\n"); 
      } else if (resIsValid(url, uvObj) == 1 && expected == 1) {
         System.out.print("Passed: " + url + " correctly marked invalid\n");
      } else if (resIsValid(url, uvObj) == 0 && expected == 1) {
         System.out.print("*FAILED*: " + url + " incorrectly marked valid\n");
      } else if (resIsValid(url,uvObj) == 1 && expected == 0) {
         System.out.print("*FAILED*: " + url + " incorrectly marked invalid\n");
      }
   } 

   /* handle random testing for 4 input partitions */
   public static void randomTest(UrlValidator uvObj) {
      System.out.print("\nRandom Testing\n\n");

      // create random generator
      Random randGen = new Random();
      
      // arrays of valid and invalid schemes 
      String[] validSchemes = {"http", "https", "ftp"}; 
      String[] invalidSchemes = {"htp", "htps", "httpr", "HTTP", "ftP", "ftps", "file", "telnet", "news", " ", "", "ssh", "tftp", "mailto", "data", "app", "svn", "tel", "ftp?", "htt.p", "http.", "x", "zz", "..."}; 

      // arrays of valid and invalid authorities
      String[] validAuths = {"www.google.com", "oregonstate.edu", "www.nasa.gov", "www.pbs.org", "www.bitpaper.io", "ir.aboutamazon.com", "en.wikipedia.org"}; 
      String[] invalidAuths = {"ww.google.com", "w.google.com", "zzz.google.com", "www..yahoo.com", "", " ", "www,goodreads.com", "www.yahoo,com", "www:yahoo.com", "www.youtube:com", "www.youtube.com:", "www.nasa.gob", ":www.nasa.gov", "www/google.com"};

      // arrays of valid and invalid paths 
      String[] validPaths = {"/index.html", "/about/us", "/jobs", "/press?ref=ftr", "/our-communities"};  
      String[] invalidPaths = {"//index.html", "/about//", "nope", "::contact.", ">!badpath", "/bad path/"}; 

      // arrays of valid and invalid queries
      String[] validQuers = {"title=Query_string&action=edit", "field1=val1&field2=val2", "example=query", ""}; 
      String[] invalidQuers = {"//badquery", "bad query", "field1=val1field2=vald2", "example==badquery", ".badquery", "badquery.", "bad::query"};


     /* BEGIN TESTING INPUT PARTITIONS */
     int testCount = 0;

     /* SCHEME: test URLs where only scheme changes
     * other parts are constant 
     *************************************************/

     // build random valid URL without adding scheme yet
     // get element at random index in each array 
     String restOfString = "://" + validAuths[randGen.nextInt(validAuths.length)] + validPaths[randGen.nextInt(validPaths.length)] + "?" + validQuers[randGen.nextInt(validQuers.length)]; 

     // test random valid schemes
     for (int i = 0; i < 3; i++) {
       // build the current URL by choosing a random valid scheme
       // append the rest of the URL to the current scheme 
       String currentURL = validSchemes[randGen.nextInt(validSchemes.length)] + restOfString;
       testCount++;
       System.out.print("Test " + testCount + ": ");
       showTestRes(currentURL, 0, uvObj); 
    }     

    // test random invalid schemes
    for (int j = 0; j < 18; j++) {
      String currentURL = invalidSchemes[randGen.nextInt(invalidSchemes.length)] + restOfString; 
      testCount++;
      System.out.print("Test " + testCount + ": ");
      showTestRes(currentURL, 1, uvObj);
    }

    /* AUTHORITY: test URLs where only authority changes
    * all other parts of URL are constant
    ***************************************************/

     // build random valid URL without adding authority yet 
     // get element at random index in each array 
     String restOfString1 = validSchemes[randGen.nextInt(validSchemes.length)] + "://";
     String restOfString2 = validPaths[randGen.nextInt(validPaths.length)] + "?" + validQuers[randGen.nextInt(validQuers.length)]; 

     // test valid authorities
     for (int k = 0; k < 6; k++) {
      String currentURL = restOfString1 + validAuths[randGen.nextInt(validAuths.length)] + restOfString2;
      testCount++;
      System.out.print("Test " + testCount + ": ");
      showTestRes(currentURL, 0, uvObj);
     }

      // test invalid authorities
      for (int m = 0; m < 13; m++) {
       String currentURL = restOfString1 + invalidAuths[randGen.nextInt(invalidAuths.length)] + restOfString2; 
       testCount++;
       System.out.print("Test " + testCount + ": ");
       showTestRes(currentURL, 1, uvObj);
      }

    /* PATH: test URLs where only path changes
    * all other parts of URL are constant
    ****************************************************/

     // build random valid URL without adding path yet
     String restOfString3 = validSchemes[randGen.nextInt(validSchemes.length)] + "://" + validAuths[randGen.nextInt(validAuths.length)];
     String restOfString4 = "?" + validQuers[randGen.nextInt(validQuers.length)];

      // test valid paths
      for (int n = 0; n < 4; n++) {
       String currentURL = restOfString3 + validPaths[randGen.nextInt(validPaths.length)] + restOfString4;
       testCount++;
       System.out.print("Test " + testCount + ": ");
       showTestRes(currentURL, 0, uvObj);
      }
      
      // test invalid paths
      for (int p = 0; p < 5; p++) {
       String currentURL = restOfString3 + invalidPaths[randGen.nextInt(invalidPaths.length)] + restOfString4;
       testCount++;
       System.out.print("Test " + testCount + ": ");
       showTestRes(currentURL, 1, uvObj);
      }

    /* QUERY: test URLs where only query changes
    ** all other parts of URL are constant
    ****************************************************/

      String restOfString5 = validSchemes[randGen.nextInt(validSchemes.length)] + "://" + validAuths[randGen.nextInt(validAuths.length)] + validPaths[randGen.nextInt(validPaths.length)] + "?";

      for (int r = 0; r < 4; r++) {
       String currentURL = restOfString5 + validQuers[randGen.nextInt(validQuers.length)]; 
       testCount++;
       System.out.print("Test " + testCount + ": ");
       showTestRes(currentURL, 0, uvObj);
      }

      for (int s = 0; s < 7; s++) {
       String currentURL = restOfString5 + invalidQuers[randGen.nextInt(invalidQuers.length)];
       testCount++;
       System.out.print("Test " + testCount + ": ");
       showTestRes(currentURL, 1, uvObj);
      }


   }


 
   
   public void testIsValid()
   {
	   String urlTest;  
	   
	   //You can use this function for programming based testing
	   String schemes[] = new String [6]; 
	   schemes[0] = "http://"; 				//valid
	   schemes[1] = "https://"; 			//valid
	   schemes[2] = "file:"; 				//valid
	   schemes[3] = ""; 					//invalid
	   schemes[4] = "5:" ;					//invalid
	   schemes[5] = "http"	;				//invalid
	   
	   String authority[] = new String[6]; 
	   authority[0] = "oregonstate.edu"; 	//valid
	   authority[1] = "www.google.com"; 	//valid
	   authority[2] = "www.nps.gov"; 		//valid
	   authority[3] = "blabigy"; 			//invalid
	   authority[4] = " "; 					//invalid
	   authority[5] = "9876"; 				//invalid
	   
	   String port[] = new String[6]; 
	   port[0] = ":8080"; 					//valid
	   port[1] = ""; 						//valid
	   port[2] = ":0"; 						//valid
	   port[3] = "hello";					//invalid
	   port[4] = "7"; 						//invalid
	   port[5] = "alisdf9"; 				//invalid
	   
	   String path[] = new String[6]; 
	   path[0] = "/software/htp/cics/index.html"; 	//valid
	   path[1] = "/videoplay"; 						//valid
	   path[2] = ""; 								//valid
	   path[3] = "hi there"; 						//invalid
	   path[4] = "alskjdf"; 						//invalid
	   path[5] = "1234567"; 						//invalid
	   
	   String query[] = new String[6]; 
	   query[0] = "Url1=http://domain.tld/&rptmode=2";
	   query[1] = ""; 
	   query[2] = "url=http://fonzi.com/&amp;name=Fonzi&amp;mood=happy&amp;coat=leather";
	   query[3] = "a;lksjdf";
	   query[4] = "invalidquery"; 
	   query[5] = "123456"; 
	   
	   UrlValidator validator = new UrlValidator();
	   
	   for (int i = 0; i < 3; i++) {
		   for (int j = 0; j < 3 ;j++) {
			   for (int k = 0; k < 3; k++) {
				   for (int l = 0; l < 3; l++) {
					   for (int m = 0; m < 3; m++) {
						   urlTest = schemes[i] + authority[j] + port[k] + path[l] + query[m];
						   
						   assertEquals(true, validator.isValid(urlTest)); 
					   }
				   }
			   }
		   }
	   }
	   
	   for (int i = 3; i < 6; i++) {
		   for (int j = 3; j < 6; j++) {
			   for (int k = 3; k < 6; k++) {
				   for (int l = 3; l < 6; l++) {
					   for (int m = 3; m < 6; m++) {
						   urlTest = schemes[i] + authority[j] + port[k] + path[l] + query[m];
						   
						   assertEquals(false, validator.isValid(urlTest)); 
					   }
				   }
			   }
		   }
	   }
	   
   }

   


}
