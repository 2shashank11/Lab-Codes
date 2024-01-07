package com.course.structure;

public class school extends house{
    private int classrooms;
    private String gradeLevel;

    public void setClasrooms(int classrooms){
        this.classrooms=classrooms;
    }

    public void setGradeLevel(String gradeLevel){
        this.gradeLevel=gradeLevel;
    }

    public int getClassrooms(){
        return classrooms;
    }

    public String getGradeLevel(){
        return gradeLevel;
    }

    public void display(int choice){
        System.out.println("\nDisplaying Entered Data: \n");
        System.out.println("Square Footage: " + getSquareFootage());
        System.out.println("Stories: " + getStories());

        if(choice==1){
            System.out.println("Bedrooms: " + getBedrooms());
            System.out.println("Bathrooms: " + getBathrooms());
        }
        else if(choice==2){
            System.out.println("Classrooms: " + getClassrooms());
            System.out.println("Grade Level: " + getGradeLevel());
        }
    }
}