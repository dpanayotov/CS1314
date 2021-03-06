package com.company;
public class Main {

    public static void main(String[] args) {
        Time time = new Time(2,3,4);
        Date date = new Date(5,6,7);
        DateTime dt= new DateTime(date, time);
        Flight fl = new Flight(dt, dt, "Burgas", "Sofia");
        Flight fl1 = new Flight(dt, dt, "Sofia", "Burgas");
        Flight[] flights = new Flight[2];
        flights[0] = fl;
        flights[1] = fl1;
        Flight fl2 = new Flight(dt,dt,"Varna", "Shumen");
        Airport ar = new Airport(flights);
        ar.addFlight(fl2);
        ar.print();
        ar.removeFlight(3);
        ar.print();
    }
}
