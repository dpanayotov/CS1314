
public class Group{
	private Student[] group = new Student[30];
	public Group(){
		for(int i=0; i<group.length; i++){
			group[i] = new Student();
		}
	}
	
	public Group(Student[] s){
		for(int i=0; i<s.length; i++)
		{
			group[i] = s[i];
		}
	}
	
	public void getAverage(){
		double average = 0;
		for(int i=0; i<group.length; i++){
			average += group[i].getGrade();
		}
		System.out.printf("Group's average grade is %.2f", average);
	}
	
	public void getMax(){
		int max=0;
		for(int i=0; i<group.length; i++){
			if(group[max].getGrade() < group[i].getGrade()){
				max = i;
			}
		}
		System.out.print("Students with best grade:");
		group[max].print();
	}
	
	public void getMin(){
		int min=0;
		for(int i=0; i<group.length; i++){
			if(group[min].getGrade() > group[i].getGrade()){
				min = i;
			}
		}
		System.out.print("Students with worst grade:");
		group[min].print();
	}
	
	public void getStudent(int facNum){
		for(int i=0; i<group.length; i++){
			if(group[i].getFacNum() == facNum){
				group[i].print();
			}
		}
	}
	
	public void sortFn(){
		for(int i=0; i<group.length; i++){
			for(int j=0; j<group.length; j++){
				if(group[i].getFacNum() < group[j].getFacNum()){
					int temp = i;
					i = j;
					j = temp;
				}
			}
		}
	}
	
	public void sortGrades(){
		for(int i=0; i<group.length; i++){
			for(int j=0; j<group.length; j++){
				if(group[i].getGrade() < group[j].getGrade()){
					int temp = i;
					i = j;
					j = temp;
				}
			}
		}
	}
	
	public final void print(){
		for(Student s:group){
			s.print();
		}
	}
	
}
