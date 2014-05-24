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
        this.flights = new Flight[2];
        for(int i=0; i<this.flights.length; i++)
        {
            this.flights[i] = new Flight();
        }
    }

    public Airport(Flight[] flights){;
        this.flights = new Flight[flights.length];
        for(int i=0; i<flights.length; i++){
            this.flights[i] = new Flight();
            this.flights[i] = flights[i];
        }
    }

    public void addFlight(Flight flight){
        Flight[] tempFlight = new Flight[flights.length+1];
        for(int i=0; i<flights.length; i++){
            tempFlight[i] = flights[i];
        }
        tempFlight[flights.length] = flight;
        flights = null;
        flights = new Flight[tempFlight.length];
        for(int i=0; i<flights.length; i++){
            flights[i] = tempFlight[i];
        }
        tempFlight = null;
    }

    public void removeFlight(int id){
        Flight[] tempFlight = new Flight[flights.length-1];
        int k=0;
        for(int i=0; i<flights.length; i++){
            if(flights[i].getId() != id){
                tempFlight[k] = flights[i];
                k++;
            }
        }
        flights = null;
        flights = new Flight[tempFlight.length];
        for(int i=0; i<flights.length; i++){
            flights[i] = tempFlight[i];
        }

        tempFlight = null;
    }

    public final void print(){
        for(Flight f : flights){
            f.print();
        }
    }
}
