
public class Student {
	private int facNum;
	private String name;
	private double grade;
	
	public Student(){
		facNum = 0;
		name = "NoName";
		grade = 0;
	}
	
	public Student(int _facNum, String _name, double _grade){
		facNum = _facNum;
		name = _name;
		grade = _grade;
	}
	
	public void setFacNum(int _facNum){
		facNum = _facNum;
	}
	
	public void setName(String _name){
		name = _name;
	}
	
	public void setGrade(double _grade){
		grade = _grade;
	}
	
	public int getFacNum(){
		return facNum;
	}
	
	public String getName(){
		return name;
	}
	
	public double getGrade(){
		return grade;
	}
	
	public void print(){
		System.out.printf("FN - %d, name - %s, grade - %.2f", facNum, name, grade);
		System.out.println();
	}
}
