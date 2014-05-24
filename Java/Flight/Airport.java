package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dpanayotov on 5/24/14.
 */
public class Airport {
    private Flight[] flights;
    public Airport(){
        flights = new Flight[2];
        for(Flight f : flights){
            f = new Flight();
        }
    }

    public Airport(Flight[] flights){;
        flights = new Flight[flights.length];
        for(int i=0; i<flights.length; i++){
            this.flights[i] = new Flight();
        }
    }

    public void addFlight(Flight flight){
        List<Flight> newFlights = new ArrayList<Flight>(Arrays.asList(flights));
        newFlights.add(flight);
        flights =  newFlights.toArray(new Flight[newFlights.size()+1]);
    }

    public void removeFlight(int id){
        ArrayList<Flight> newFlights = new ArrayList<Flight>(Arrays.asList(flights));
        for(int i=0; i<flights.length; i++){
            if(this.flights[i].getId() == id){
                newFlights.remove(i);
            }
        }
        flights = newFlights.toArray(new Flight[newFlights.size()-1]);
    }

    public final void print(){
        for(Flight f : flights){
            f.print();
        }
    }
}
