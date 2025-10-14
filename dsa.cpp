Problem 1: Student Marks Calculation 

Question: 
 Write a program to input marks of students in 5 subjects, calculate total, average, and grade using methods and handle invalid marks using exception handling. 

Code: 

import java.util.*; 
public class StudentMarks { 
    static char grade(double avg){ 
        if(avg>=90) return 'A'; 
        else if(avg>=75) return 'B'; 
        else if(avg>=50) return 'C'; 
        else return 'F'; 
    } 
    public static void main(String[] args){ 
        Scanner sc=new Scanner(System.in); 
        int total=0; 
        try{ 
            for(int i=1;i<=5;i++){ 
                System.out.println("Enter marks of subject "+i+": "); 
                int m=sc.nextInt(); 
                if(m<0||m>100) throw new Exception("Invalid marks!"); 
                total+=m; 
            } 
            double avg=total/5.0; 
            System.out.println("Total: "+total+"\nAverage: "+avg+"\nGrade: "+grade(avg)); 
        }catch(Exception e){System.out.println(e.getMessage());} 
    } 
} 

Problem 2: Item Bill Calculation 

Question: 
 Accept item names, price, and quantity. Calculate total, apply discount if total > 2000, and display formatted bill using methods. 

Code: 

import java.util.*; 
public class ItemBill { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter number of items: "); 
        int n = sc.nextInt(); 
 
        String[] name = new String[n]; 
        double[] price = new double[n]; 
        int[] qty = new int[n]; 
        double total = 0; 
 
        for (int i = 0; i < n; i++) { 
            System.out.println("\nItem " + (i + 1) + ":"); 
            System.out.print("Name: "); name[i] = sc.next(); 
            System.out.print("Price: "); price[i] = sc.nextDouble(); 
            System.out.print("Qty: "); qty[i] = sc.nextInt(); 
        } 
 
        System.out.println("\n------ Final Bill ------"); 
        System.out.println("Name\tPrice\tQty\tTotal"); 
        for (int i = 0; i < n; i++) { 
            double itemTotal = price[i] * qty[i]; 
            System.out.println(name[i] + "\t" + price[i] + "\t" + qty[i] + "\t" + itemTotal); 
            total += itemTotal; 
        } 
 
        if (total > 2000) { 
            System.out.println("\nDiscount Applied (10%)"); 
            total *= 0.9; 
        } 
 
        System.out.println("------------------------"); 
        System.out.println("Total Bill: Rs." + total); 
    } 
} 

Problem 3: Count Words and Occurrences 

Question: 
 Take a sentence and count number of words and occurrences of a specific word using arrays and string methods. 

Code: 

import java.util.*; 
public class WordCount { 
    public static void main(String[] args){ 
        Scanner sc=new Scanner(System.in); 
        System.out.println("Enter sentence:"); String s=sc.nextLine(); 
        String[] words=s.split("\\s+"); 
        System.out.println("Word count: "+words.length); 
        System.out.print("Word to find: "); String w=sc.next(); 
        int c=0; for(String x:words) if(x.equalsIgnoreCase(w)) c++; 
        System.out.println("Occurrences of '"+w+"': "+c); 
    } 
} 

Problem 4: Password Strength Checker 

Question: 
 Check password strength: length ≥8, contains uppercase, lowercase, digit, and symbol; throw exception if invalid. 

Code: 

import java.util.*; 
public class PasswordCheck { 
    static void check(String p)throws Exception{ 
        if(p.length()<8||!p.matches(".*[A-Z].*")||!p.matches(".*[a-z].*")||!p.matches(".*\\d.*")||!p.matches(".*\\W.*")) 
            throw new Exception("Weak Password!"); 
        System.out.println("Strong Password!"); 
    } 
    public static void main(String[] a){ 
        Scanner sc=new Scanner(System.in); 
        System.out.print("Enter password: "); 
        try{check(sc.next());}catch(Exception e){System.out.println(e.getMessage());} 
    } 
} 

Problem 5: ATM Simulation 

Question: 
 Simulate ATM operations like deposit, withdraw, and check balance. Use methods and handle insufficient balance with exception handling. 

Code: 

import java.util.*; 
public class ATM { 
    static double bal=1000; 
    static void deposit(double a){bal+=a;} 
    static void withdraw(double a)throws Exception{if(a>bal)throw new Exception("Insufficient balance!");bal-=a;} 
    public static void main(String[] args){ 
        Scanner sc=new Scanner(System.in); 
        try{ 
            System.out.print("1.Deposit 2.Withdraw 3.Check: "); 
            int ch=sc.nextInt(); 
            if(ch==1) deposit(sc.nextDouble()); 
            else if(ch==2) withdraw(sc.nextDouble()); 
            System.out.println("Balance: ₹"+bal); 
        }catch(Exception e){System.out.println(e.getMessage());} 
    } 
} 

Problem 6: Salary Calculation 

Question: 
 Accept basic salary and compute HRA, DA, PF, and gross salary using methods and handle invalid inputs with exceptions. 

Code: 

import java.util.*; 
 
public class SalaryCalculator { 
    static double hra(double b){ return 0.10*b; } 
    static double da(double b){ return 0.05*b; } 
    static double pf(double b){ return 0.12*b; } 
    static double gross(double b){ return b + hra(b) + da(b) - pf(b); } 
 
    public static void main(String[] args){ 
        Scanner sc = new Scanner(System.in); 
        try{ 
            System.out.print("Enter Basic Salary: "); 
            double b = sc.nextDouble(); 
            if(b <= 0) throw new Exception("Salary must be > 0"); 
            System.out.println("HRA: " + hra(b) + "\nDA: " + da(b) + "\nPF: " + pf(b)); 
            System.out.println("Gross Salary: " + gross(b)); 
        }catch(Exception e){ 
            System.out.println("Error: " + e.getMessage()); 
        } 
    } 
} 

Problem 7: Membership Discount 

Question: 
 Accept total bill and membership type (Silver/Gold/Platinum) and apply discounts using if-else and methods. 

Code: 

import java.util.*; 
public class Membership { 
    static double discount(double b,String t){ 
        if(t.equalsIgnoreCase("Silver")) b*=0.95; 
        else if(t.equalsIgnoreCase("Gold")) b*=0.9; 
        else if(t.equalsIgnoreCase("Platinum")) b*=0.85; 
        return b; 
    } 
    public static void main(String[] a){ 
        Scanner sc=new Scanner(System.in); 
        System.out.print("Enter total bill amount: "); double bill=sc.nextDouble(); 
        System.out.print("Enter your Membership type(Silver/Gold/Platinum): "); String type=sc.next(); 
        System.out.println("Payable amount after discount: Rs."+discount(bill,type)); 
    } 
} 

Problem 8: Product Stock Management 

Question: 
 For n products, store product name, price, and quantity in arrays. Calculate total stock value and handle out-of-stock errors via exception handling. 

Code: 

import java.util.*; 
public class ProductStock { 
    public static void main(String[] args){ 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter number of products: "); 
        int n = sc.nextInt(); 
        String[] name = new String[n]; 
        double[] price = new double[n]; 
        int[] qty = new int[n]; 
        double total = 0; 
 
        try { 
            for(int i = 0; i < n; i++) { 
                System.out.println("\nProduct " + (i + 1) + ":"); 
                System.out.print("Name: "); name[i] = sc.next(); 
                System.out.print("Price: "); price[i] = sc.nextDouble(); 
                System.out.print("Qty: "); qty[i] = sc.nextInt(); 
                if(qty[i] == 0) throw new Exception(name[i] + " is out of stock!"); 
                total += price[i] * qty[i]; 
            } 
 
            System.out.println("\n--- Product Details ---"); 
            for(int i = 0; i < n; i++) 
                System.out.println((i + 1) + ". " + name[i] + " | Price: Rs." + price[i] + " | Qty: " + qty[i]); 
 
            System.out.println("Total Stock Value: ₹" + total); 
 
        } catch(Exception e) { 
            System.out.println("Error: " + e.getMessage()); 
        } 
    } 
} 

2 

Problem 1: Coffee Order Processing 

Question: 

Process a coffee order: take customer size choice, calculate total price based on size and add-ons, and handle a list of 5 drink types. 

Code: 

import java.util.*; 
class CoffeeOrder { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        String[] drinks = {"Espresso", "Latte", "Cappuccino", "Mocha", "Americano"}; 
        System.out.println("Choose drink (1-5): "); 
        for(int i=0;i<drinks.length;i++) 
            System.out.println((i+1)+". "+drinks[i]); 
        int choice = sc.nextInt(); 
        System.out.print("Size (S/M/L): "); 
        char size = sc.next().charAt(0); 
        double price = size=='S'Rs.100:size=='M'Rs.150:200; 
        System.out.print("Add milk (+20)Rs. (y/n): "); 
        if(sc.next().equalsIgnoreCase("y")) price += 20; 
        System.out.println("You ordered " + drinks[choice-1] + " | Total: Rs." + price); 
    } 
} 

Problem 2: Calculator Using Switch 

Question: 

Create a method that accepts two numbers and an operation symbol. Use a switch to perform and return the result of addition, subtraction, multiplication, or division. 

Code: 

import java.util.*; 
class Calculator { 
    static double calc(double a, double b, char op) { 
        switch(op) { 
            case '+': return a + b; 
            case '-': return a - b; 
            case '*': return a * b; 
            case '/': return b != 0 ? a / b : 0; 
            default: return 0; 
        } 
    } 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter a,b,operation: "); 
        double a = sc.nextDouble(), b = sc.nextDouble(); 
        char op = sc.next().charAt(0); 
        System.out.println("Result: " + calc(a, b, op)); 
    } 
} 

Problem 3: Count Characters 

Question: 

Input a string and count vowels, consonants, digits, and special characters using loops and conditionals. 

Code: 

import java.util.*; 
class CountChars { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter string: "); 
        String s = sc.nextLine(); 
        int v = 0, c = 0, d = 0, sp = 0; 
        for(char ch : s.toCharArray()) { 
            if(Character.isDigit(ch)) d++; 
            else if("AEIOUaeiou".indexOf(ch) >= 0) v++; 
            else if(Character.isLetter(ch)) c++; 
            else sp++; 
        } 
        System.out.println("Vowels=" + v + " Consonants=" + c + " Digits=" + d + " Special=" + sp); 
    } 
} 

Problem 4: Apply Interest 

Question: 

For n customers, input name, account type, and balance. Apply 4% interest for savings and 6% for fixed accounts, then display updated balances. 

Code: 

import java.util.*; 
class BankInterest { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter no. of customers: "); 
        int n = sc.nextInt(); 
 
        for(int i = 1; i <= n; i++) { // start from 1 for customer numbering 
            System.out.println("\nCustomer " + i + ":"); // display customer number 
            System.out.print("Name: ");  
            String name = sc.next(); 
            System.out.print("Type (savings/fixed): ");  
            String type = sc.next(); 
            System.out.print("Balance: ");  
            double bal = sc.nextDouble(); 
 
            double rate = type.equalsIgnoreCase("savings") ? 0.04 : 0.06; 
            bal += bal * rate; 
 
            System.out.println(name + "'s updated balance: " + bal); 
        } 
    } 
} 

Problem 5: Temperature Conversion 

Question: 

Read 5 daily temperatures into an array. Use a loop and a method to convert each temperature from Celsius to Fahrenheit, displaying both. 

Code: 

import java.util.*; 
class TempConvert { 
    static double toF(double c) { return (c * 9 / 5) + 32; } 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        double[] t = new double[5]; 
        System.out.println("Enter 5 Celsius temps:"); 
        for(int i = 0; i < 5; i++) t[i] = sc.nextDouble(); 
        for(double c : t) 
            System.out.println(c + "°C = " + toF(c) + "°F"); 
    } 
} 

Problem 7: Palindrome Check 

Question: 

Input a string and check if it’s a palindrome (ignore case and spaces). Use string methods and exception handling. 

Code: 

import java.util.*; 
class PalindromeCheck { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        try { 
            System.out.print("Enter string: "); 
            String s = sc.nextLine().replaceAll("\\s+", "").toLowerCase(); 
            String rev = new StringBuilder(s).reverse().toString(); 
            System.out.println(s.equals(rev) ? "Palindrome" : "Not Palindrome"); 
        } catch(Exception e) { 
            System.out.println("Error!"); 
        } 
    } 
} 

Problem 8: Character Replacement 

Question: 

Read a word (String). Use a loop and a switch on each character to replace 'a' with '4', 'e' with '3', and 'o' with '0'. 

Code: 

import java.util.*; 
class ReplaceChars { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter word: "); 
        String w = sc.nextLine(); 
        StringBuilder res = new StringBuilder(); 
        for(char ch : w.toCharArray()) { 
            switch(ch) { 
                case 'a': res.append('4'); break; 
                case 'e': res.append('3'); break; 
                case 'o': res.append('0'); break; 
                default: res.append(ch); 
            } 
        } 
        System.out.println("Modified: " + res); 
    } 
} 

 

 

 

 

 

 

 

 