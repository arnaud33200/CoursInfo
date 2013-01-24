package contact.services;


public class EntityNotPersisted extends Exception {

	private Object entity;

	public Object getEntity() {
		return entity;
	}

	public void setEntity(Object entity) {
		this.entity = entity;
	}
	
}
