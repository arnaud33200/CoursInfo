
package iut.jee.clients.soapservices;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for add complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="add">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="hellobean" type="{http://soap.jee.iut/}helloBean" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "add", propOrder = {
    "hellobean"
})
public class Add {

    protected HelloBean hellobean;

    /**
     * Gets the value of the hellobean property.
     * 
     * @return
     *     possible object is
     *     {@link HelloBean }
     *     
     */
    public HelloBean getHellobean() {
        return hellobean;
    }

    /**
     * Sets the value of the hellobean property.
     * 
     * @param value
     *     allowed object is
     *     {@link HelloBean }
     *     
     */
    public void setHellobean(HelloBean value) {
        this.hellobean = value;
    }

}
