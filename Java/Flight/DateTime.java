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
        this.d = d;
        this.t = t;
    }

    public void print()
    {
        this.t.print();
        this.d.print();
    }
}
