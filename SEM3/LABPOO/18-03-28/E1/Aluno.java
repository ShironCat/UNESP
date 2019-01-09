public class Aluno {

    private String id;
    private String name;
    private String ra;
    private String email;
    private String phoneNumber;

    public Aluno(String id, String name, String ra) {
        this.id = id;
        this.name = name;
        this.ra = ra;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getRa() {
        return ra;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
}