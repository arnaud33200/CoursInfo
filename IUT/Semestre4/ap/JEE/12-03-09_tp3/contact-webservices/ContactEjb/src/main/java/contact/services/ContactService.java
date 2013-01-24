package contact.services;

import java.util.List;

import contact.entities.Contact;

public interface ContactService {

	Contact add (Contact e) ;

	List<Contact> getAll();

	Contact get(String parameter);
	
	Contact update (Contact e) throws EntityNotPersisted;
	
	boolean delete (String name);
}
