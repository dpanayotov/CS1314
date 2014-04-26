import java.util.*;

public class Tuna {
	public static void main(String[] args) {
		Student[] students = new Student[10];
		for(int i=0; i<students.length; i++){
			students[i] = new Student();
		}
		Group g = new Group(students);
		g.print();
	}
}
