package com.company;
public class Main {

    public static void main(String[] args) {
        Time time = new Time(2,3,4);
        Date date = new Date(5,6,7);
        DateTime dt= new DateTime(date, time);
        Flight fl = new Flight(dt, dt, "Burgas", "Sofia");
        Flight fl1 = new Flight(dt, dt, "Sofia", "Burgas");
        fl.print();
        fl1.print();
    }
}
