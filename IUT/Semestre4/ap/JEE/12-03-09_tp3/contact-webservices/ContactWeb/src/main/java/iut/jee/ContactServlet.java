package iut.jee;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.NoSuchElementException;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.sun.org.apache.bcel.internal.generic.NEW;

import contact.entities.Contact;
import contact.services.ContactService;
import contact.services.EntityNotPersisted;

/**
 * Servlet implementation class HelloWorld
 */
@WebServlet("/contact")
public class ContactServlet extends HttpServlet {
	
	public <T> T getService(String remotePath) {
		Context context;
		T s = null;
		try {
			context = new InitialContext();
			s = (T) context.lookup(remotePath);
		} catch (NamingException e) {
			e.printStackTrace();
		}
		return s;
	}
	public ContactService getMonService() {
		return getService("ContactEAR/ContactServiceImpl/remote");
	}	
	
	private static final long serialVersionUID = 1L;

    /**
     * Default constructor. 
     */
    public ContactServlet() {
        
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//exoPremierServlet(response);
		String actionParameter = (String)request.getParameter("action");
		if(actionParameter == null || actionParameter.equals("viewAll")) {
			request.setAttribute("contacts", getMonService().getAll());
			request.getRequestDispatcher("ViewAllContacts.jsp").forward(request, response);
		}
		if(actionParameter.equals("add")) {
			request.setAttribute("mode", new String("add"));
			request.getRequestDispatcher("EditContact.jsp").forward(request, response);
		} if(actionParameter.equals("view")) {
			request.setAttribute("contact", getMonService().get((String) request.getParameter("name")));
			request.getRequestDispatcher("ViewContact.jsp").forward(request, response);
		} if(actionParameter.equals("edit")) {
			request.setAttribute("mode", new String("edit"));
			request.getSession().putValue("contact", getMonService().get((String) request.getParameter("name")));
			request.getRequestDispatcher("EditContact.jsp").forward(request, response);
		} if(actionParameter.equals("del")) {
			getMonService().delete((String) request.getParameter("name"));
			request.setAttribute("contacts", getMonService().getAll());
			request.getRequestDispatcher("ViewAllContacts.jsp").forward(request, response);
		}
	}
	
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Contact c = new Contact();
		c.setName((String) request.getParameter("name"));
		c.setPhone((String) request.getParameter("phone"));
		c.setEmail((String) request.getParameter("email"));
		
		Date bday = new Date();
		DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
		try {
			bday = dateFormat.parse((String) request.getParameter("birthday"));
		} catch (ParseException e) {
			e.printStackTrace();
		}
		
		try {
			getMonService().update(c);
		} catch (EntityNotPersisted e) {
			getMonService().add(c);
		}
		
		request.setAttribute("contacts", getMonService().getAll());
		request.getRequestDispatcher("ViewAllContacts.jsp").forward(request, response);
	}

	private void exoPremierServlet(HttpServletResponse response)
			throws IOException {
		Contact c = createEtudiant();
		
		PrintWriter writer = response.getWriter();
		writer.println(c.getName());
		writer.println(c.getEmail());
		writer.println(c.getPhone());
	}

	private Contact createEtudiant() {
		Contact c = new Contact();
		c.setName("Vincent");
		Date bday = new Date();
		
		DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
		try {
			bday = dateFormat.parse("1984-12-26");
		} catch (ParseException e) {
			e.printStackTrace();
		}
		//c.setBirthday(bday);
		
		c.setPhone("0908090989");
		c.setEmail("rabeux@labri.fr");
		return c;
	}

	

}
