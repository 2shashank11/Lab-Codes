package com.course.structure;

public class house extends building{
    private int bedrooms;
    private int bathrooms;

    public void setBedrooms(int bedrooms){
        this.bedrooms=bedrooms;
    }

    public void setBathrooms(int bathrooms){
        this.bathrooms=bathrooms;
    }

    public int getBedrooms(){
        return this.bedrooms;
    }

    public int getBathrooms(){
        return this.bathrooms;
    }
}