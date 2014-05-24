package com.company;
public class Main {

    public static void main(String[] args) {
        Time t = new Time(2,3,4);
        Date d = new Date(5,6,7);
        DateTime da = new DateTime(d, t);
        d.print();
    }
}
