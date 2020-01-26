import java.util.Scanner;

public class Question3 {
    static int forwardHashFunc(String str, int len) {
        char[] chars = str.toCharArray();
        int fwdHash = 0;
        for (int i = 0; i < len; i++) {
            fwdHash += (i + 1) * (int) chars[i];
        }
        return (fwdHash);
    }

    static int reverseHashFunc(String str, int len) {
        String temp = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            temp = temp + str.charAt(i);
        }
        char[] chars = temp.toCharArray();
        int rvsdHash = 0;
        for (int i = 0; i < len; i++) {
            rvsdHash += (i + 1) * (int) chars[i];
        }
        return (rvsdHash);
    }

    public static void main(String[] args) {
        int option , count =0;
        Scanner scan = new Scanner(System.in);
        System.out.println("\n**********WELCOME TO PALINDROME CHECKER**********");
        System.out.println("Enter the string : ");        
        String stringA = scan.nextLine();
        //stringA = scan.nextLine();
        System.out.println("Please enter number of queries you need evaluate: ");
        option = scan.nextInt();
        System.out.println("*************************************************");

        while (option > count) {        
           
            System.out.println("Enter the Substring Starting point : ");
            int subsStart = scan.nextInt();
            System.out.print("");
            System.out.println("Enter the Substring Ending point : ");
            int subsEnd = scan.nextInt();
            subsEnd= subsEnd+1;
            System.out.println("");

            //System.out.println("\nOriginal String : " + stringA + "\n");

            String substring = stringA.substring(subsStart, subsEnd);
            //System.out.println("Substring to check :"+substring);

            String substring2 = substring.replaceAll("\\s", ""); // for multiple words

            int length = substring2.length();
            int Hashed = forwardHashFunc(substring2, length);
            int revd = reverseHashFunc(substring2, length);

            
            if (Hashed == revd){ // compare forward hashed and reverse hashed values
                System.out.println("["+subsStart+", "+(subsEnd-1)+"] --> Substring \""+substring+"\" is a palindrome.");
                System.out.println("");
            }else{
                System.out.println("["+subsStart+", "+(subsEnd-1)+"] --> Substring \""+substring+"\" is not a palindrome.");
            }
            System.out.println("*************************************************");
            count++;
        }

        //scan.close();
    }

}