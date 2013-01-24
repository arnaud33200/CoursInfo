package contact.services;

import java.util.List;

import javax.ejb.Remote;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.NoResultException;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import contact.entities.Contact;

@Stateless
@Remote(ContactService.class)
public class ContactServiceImpl implements ContactService {
	
	@PersistenceContext(name="MyEntity") 
	private EntityManager em ;

	public Contact add (Contact e)  {
		em.persist(e);
		return e;
	}

	@Override
	public List<Contact> getAll() {
		
		/*
		 // With Criteria API
		CriteriaBuilder cb = em.getCriteriaBuilder();
		CriteriaQuery<Contact> cq = cb.createQuery(Contact.class);
		Root<Contact> from = cq.from(Contact.class);
		
		CriteriaQuery<Contact> select = cq.select(from);
        select.orderBy(cb.asc(from.get("name")));
        return em.createQuery(select).getResultList();*/
		
		return em.createQuery("select c from Contact c order by c.name").getResultList();
		
	}

	@Override
	public Contact get(String name) throws NoResultException {
		/*
		 // With Criteria API
		
		CriteriaBuilder cb = em.getCriteriaBuilder();
		CriteriaQuery<Contact> cq = cb.createQuery(Contact.class);
		Root<Contact> root = cq.from(Contact.class);
		
		cq.where(cb.equal(root.get("name"), name));
		return (Contact) em.createQuery(cq).getSingleResult();
		*/

		/*
		 // With a Query 
		 Query q =em.createQuery("select c from Contact c where c.name like :name");
		q.setParameter("name", name);
		return (Contact) q.getSingleResult();*/
		
		return em.find(Contact.class, name);
	}

	@Override
	public Contact update(Contact e) throws EntityNotPersisted {
		try {
			get(e.getName());
		} catch (NoResultException ex) {
			throw new EntityNotPersisted();
		}
		return em.merge(e);
	}

	@Override
	public boolean delete(String name) {
		em.remove(get(name));
		return get(name) == null;
	}
}
