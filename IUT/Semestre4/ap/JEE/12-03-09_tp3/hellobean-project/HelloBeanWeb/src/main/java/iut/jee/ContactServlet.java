package iut.jee;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class HelloWorld
 */
@WebServlet("/contact")
public class ContactServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	HashMap<String, Contact> contacts;
    /**
     * Default constructor. 
     */
    public ContactServlet() {
        contacts = new HashMap<String, Contact>();
        Contact c = createEtudiant();
        contacts.put(c.getName(), c);
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//exoPremierServlet(response);
		String actionParameter = (String)request.getParameter("action");
		if(actionParameter == null || actionParameter.equals("viewAll")) {
			request.setAttribute("contacts", contacts);
			request.getRequestDispatcher("ViewAllContacts.jsp").forward(request, response);
		}
		if(actionParameter.equals("add"))
			request.getRequestDispatcher("EditContact.jsp").forward(request, response);
		
		if(actionParameter.equals("view")) {
			request.setAttribute("contact", contacts.get((String) request.getParameter("name")));
			request.getRequestDispatcher("ViewContact.jsp").forward(request, response);
		}
		if(actionParameter.equals("edit")) {
			request.getSession().putValue("contact", contacts.get((String) request.getParameter("name")));
			request.getRequestDispatcher("EditContact.jsp").forward(request, response);
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
		c.setBirthday(bday);

		contacts.put(c.getName(), c);
		request.setAttribute("contacts", contacts);
		request.getRequestDispatcher("ViewAllContacts.jsp").forward(request, response);
	}

	private void exoPremierServlet(HttpServletResponse response)
			throws IOException {
		Contact c = createEtudiant();
		
		PrintWriter writer = response.getWriter();
		writer.println(c.getName());
		writer.println(c.getEmail());
		writer.println(c.getPhone());
		writer.println(c.getBirthday().toString());
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
		c.setBirthday(bday);
		c.setPhone("0908090989");
		c.setEmail("rabeux@labri.fr");
		return c;
	}

	

}
