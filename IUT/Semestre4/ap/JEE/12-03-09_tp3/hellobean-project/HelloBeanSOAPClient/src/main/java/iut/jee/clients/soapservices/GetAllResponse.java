
package iut.jee.clients.soapservices;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for getAllResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="getAllResponse">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="hellobeanlist" type="{http://soap.jee.iut/}helloBean" maxOccurs="unbounded" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "getAllResponse", propOrder = {
    "hellobeanlist"
})
public class GetAllResponse {

    protected List<HelloBean> hellobeanlist;

    /**
     * Gets the value of the hellobeanlist property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the hellobeanlist property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getHellobeanlist().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link HelloBean }
     * 
     * 
     */
    public List<HelloBean> getHellobeanlist() {
        if (hellobeanlist == null) {
            hellobeanlist = new ArrayList<HelloBean>();
        }
        return this.hellobeanlist;
    }

}
