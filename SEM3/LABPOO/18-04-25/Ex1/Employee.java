public class Employee {

    private String first_name;
    private String last_name;
    private double wage;

    public Employee (String first_name, String last_name, double wage) {
        this.first_name = first_name;
        this.last_name = last_name;
        this.wage = wage;
    }

    public void setFirst_name(String first_name) {
        this.first_name = first_name;
    }

    public String getFirst_name() {
        return first_name;
    }

    public void setLast_name(String last_name) {
        this.last_name = last_name;
    }

    public String getLast_name() {
        return last_name;
    }

    public void setWage(double wage) {
        this.wage = wage;
    }

    public double getWage() {
        return wage;
    }
    
}