package com.company;

/**
 * Created by dpanayotov on 5/24/14.
 */
public class DateTime {
    private Date d;
    private Time t;
    public DateTime()
    {
        d = new Date();
        t = new Time();
    }

    public DateTime(Date d, Time t){
        this.d = new Date(d.getDay(), d.getMonth(), d.getYear());
        this.t = new Time(t.getHour(), t.getMinute(), t.getSecond());
    }

    public void print()
    {
        this.t.print();
        this.d.print();
    }
}
