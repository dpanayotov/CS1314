package com.company;

/**
 * Created by dpanayotov on 5/24/14.
 */
public class Flight {
    private DateTime arrival, departure;
    private String from, to;
    private int id;
    private static int flightNumber=0;

    public Flight()
    {
        arrival = new DateTime();
        departure = new DateTime();
        from = "asd";
        to = "dsa";
        id = ++flightNumber;
    }

    public Flight(DateTime arrival, DateTime departure, String from, String to){
        this.arrival = arrival;
        this.departure = departure;
        this.from = from;
        this.to = to;
        id = ++flightNumber;
    }

    public final void print(){
        System.out.printf("Flight ID: %d \nFrom: %s \nTo: %s \nDeparture: ", this.id, this.from, this.to);
        this.departure.print();
        System.out.print("\nArrival: ");
        this.arrival.print();
        System.out.println("\n");
    }
}
