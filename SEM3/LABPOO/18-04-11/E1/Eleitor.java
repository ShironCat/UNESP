import java.util.Calendar;
import java.util.Date;

import com.sun.xml.internal.stream.dtd.DTDGrammarUtil;

public class Eleitor {

    private String nomeEleitor;
    private Date dataNascimentoEleitor;
    private String numeroInscricaoEleitor;
    private String zonaEleitor;
    private String secaoEleitor;
    private String municipioEleitor;
    private String ufEleitor;
    private Date dataEmissaoEleitor;
    
    public Eleitor(String nomeEleitor, Date dataNascimentoEleitor, String numeroInscricaoEleitor, String zonaEleitor, String secaoEleitor, String municipioEleitor, String ufEleitor, Date dataEmissaoEleitor) {
        this.nomeEleitor = nomeEleitor;
        this.dataNascimentoEleitor = dataNascimentoEleitor;
        this.numeroInscricaoEleitor = numeroInscricaoEleitor;
        this.zonaEleitor = zonaEleitor;
        this.secaoEleitor = secaoEleitor;
        this.municipioEleitor = municipioEleitor;
        this.ufEleitor = ufEleitor;
        this.dataEmissaoEleitor = dataEmissaoEleitor;
    }

    public void setNomeEleitor(String nomeEleitor) {
        this.nomeEleitor = nomeEleitor;
    }

    public String getNomeEleitor() {
        return nomeEleitor;
    }

    public void setDataNascimentoEleitor(Date dataNascimentoEleitor) {
        this.dataNascimentoEleitor = dataNascimentoEleitor;
    }

    public Date getDataNascimentoEleitor() {
        return dataNascimentoEleitor;
    }

    public void setNumeroInscricaoEleitor(String numeroInscricaoEleitor) {
        this.numeroInscricaoEleitor = numeroInscricaoEleitor;
    }

    public String getNumeroInscricaoEleitor() {
        return numeroInscricaoEleitor;
    }

    public void setZonaEleitor(String zonaEleitor) {
        this.zonaEleitor = zonaEleitor;
    }

    public String getZonaEleitor() {
        return zonaEleitor;
    }

    public void setSecaoEleitor(String secaoEleitor) {
        this.secaoEleitor = secaoEleitor;
    }

    public String getSecaoEleitor() {
        return secaoEleitor;
    }

    public void setMunicipioEleitor(String municipioEleitor) {
        this.municipioEleitor = municipioEleitor;
    }

    public String getMunicipioEleitor() {
        return municipioEleitor;
    }

    public void setUfEleitor(String ufEleitor) {
        this.ufEleitor = ufEleitor;
    }

    public String getUfEleitor() {
        return ufEleitor;
    }

    public void setDataEmissaoEleitor(Date dataEmissaoEleitor) {
        this.dataEmissaoEleitor = dataEmissaoEleitor;
    }

    public Date DataEmissaoEleitor() {
        return dataEmissaoEleitor;
    }
    
    public boolean checaIdade(Date dataNascimentoEleitor) {
        Date date = new Date();
        if((date.get(Calendar.YEAR) - dataNascimentoEleitor.get(Calendar.YEAR)) >= 16) {
            return true;
        } else {
            return false;
        }
    }

    public boolean checaEmissao(Date dataEmissaoEleitor) {
		Date date = new Date();
		if(date.compareTo(dataEmissaoEleitor) <= 0) {
			return true;
		} else {
			return false;
		}
    }

}