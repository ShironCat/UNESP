public class ComissionedEmployee extends Employee{

    private double comission;
    private int unit;

    public ComissionedEmployee(String first_name, String last_name, double wage, double comission) {
        super(first_name, last_name, wage);
        this.comission = comission;
    }

    public void setComission(double comission) {
        this.comission = comission;
    }

    public double getComission() {
        return comission;
    }

    public void setUnit(int unit) {
        this.unit = unit;
    }

    public double getUnit() {
        return unit;
    }
    
}