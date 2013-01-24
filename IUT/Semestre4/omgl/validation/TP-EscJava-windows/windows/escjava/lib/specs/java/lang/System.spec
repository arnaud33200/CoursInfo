/* Modifications Copyright 2000 by Compaq Computer Corporation */
/*
 * @(#)System.java	1.95 98/10/17
 *
 * Copyright 1994-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

package java.lang;

import java.io.*;
import java.util.Properties;
import java.util.PropertyPermission;
import java.util.StringTokenizer;
import sun.net.InetAddressCachePolicy;

/**
 * The <code>System</code> class contains several useful class fields 
 * and methods. It cannot be instantiated. 
 * <p>
 * Among the facilities provided by the <code>System</code> class 
 * are standard input, standard output, and error output streams; 
 * access to externally defined "properties"; a means of 
 * loading files and libraries; and a utility method for quickly 
 * copying a portion of an array. 
 *
 * @author  Arthur van Hoff 
 * @version 1.95, 10/17/98
 * @since   JDK1.0
 */
public final
class System {
    /* First thing---register the natives */
    private static native void registerNatives();
    static {
        registerNatives();
    }

    /** Don't let anyone instantiate this class */
    private System() {
    }

    /**
     * The "standard" input stream. This stream is already 
     * open and ready to supply input data. Typically this stream 
     * corresponds to keyboard input or another input source specified by 
     * the host environment or user. 
     */
    public final static /*@non_null*/ InputStream in = nullInputStream();

    /**
     * The "standard" output stream. This stream is already 
     * open and ready to accept output data. Typically this stream 
     * corresponds to display output or another output destination 
     * specified by the host environment or user. 
     * <p>
     * For simple stand-alone Java applications, a typical way to write 
     * a line of output data is: 
     * <blockquote><pre>
     *     System.out.println(data)
     * </pre></blockquote>
     * <p>
     * See the <code>println</code> methods in class <code>PrintStream</code>. 
     *
     * @see     java.io.PrintStream#println()
     * @see     java.io.PrintStream#println(boolean)
     * @see     java.io.PrintStream#println(char)
     * @see     java.io.PrintStream#println(char[])
     * @see     java.io.PrintStream#println(double)
     * @see     java.io.PrintStream#println(float)
     * @see     java.io.PrintStream#println(int)
     * @see     java.io.PrintStream#println(long)
     * @see     java.io.PrintStream#println(java.lang.Object)
     * @see     java.io.PrintStream#println(java.lang.String)
     */
    public final static /*@non_null*/PrintStream out = nullPrintStream();

    /**
     * The "standard" error output stream. This stream is already 
     * open and ready to accept output data. 
     * <p>
     * Typically this stream corresponds to display output or another 
     * output destination specified by the host environment or user. By 
     * convention, this output stream is used to display error messages 
     * or other information that should come to the immediate attention 
     * of a user even if the principal output stream, the value of the 
     * variable <code>out</code>, has been redirected to a file or other 
     * destination that is typically not continuously monitored. 
     */
    public final static /*@non_null*/ PrintStream err = nullPrintStream();

    /* The security manager for the system.
     */
    private static SecurityManager security = null;

    /**
     * Reassigns the "standard" input stream.
     * 
     * <p>First, if there is a security manager, its <code>checkPermission</code> 
     * method is called with a <code>RuntimePermission("setIO")</code> permission
     *  to see if it's ok to reassign the "standard" input stream. 
     * <p>
     * 
     * @param in the new standard input stream.
     * 
     * @throws SecurityException
     *        if a security manager exists and its 
     *        <code>checkPermission</code> method doesn't allow 
     *        reassigning of the standard input stream.
     * 
     * @see SecurityManager#checkPermission
     * @see java.lang.RuntimePermission
     * 
     * @since   JDK1.1
     */
    public static void setIn(InputStream in) {
	checkIO();
	setIn0(in);
    }

    /**
     * Reassigns the "standard" output stream.
     *
     * <p>First, if there is a security manager, its <code>checkPermission</code> 
     * method is called with a <code>RuntimePermission("setIO")</code> permission
     *  to see if it's ok to reassign the "standard" output stream. 
     * 
     * @param out the new standard output stream.
     * 
     * @throws SecurityException
     *        if a security manager exists and its 
     *        <code>checkPermission</code> method doesn't allow 
     *        reassigning of the standard output stream.
     * 
     * @see SecurityManager#checkPermission
     * @see java.lang.RuntimePermission
     * 
     * @since   JDK1.1
     */
    public static void setOut(PrintStream out) {
	checkIO();
	setOut0(out);
    }

    /**
     * Reassigns the "standard" error output stream.
     *
     * <p>First, if there is a security manager, its <code>checkPermission</code> 
     * method is called with a <code>RuntimePermission("setIO")</code> permission
     *  to see if it's ok to reassign the "standard" error output stream. 
     * 
     * @param out the new standard error output stream.
     * 
     * @throws SecurityException
     *        if a security manager exists and its 
     *        <code>checkPermission</code> method doesn't allow 
     *        reassigning of the standard error output stream.
     * 
     * @see SecurityManager#checkPermission
     * @see java.lang.RuntimePermission
     * 
     * @since   JDK1.1
     */
    public static void setErr(PrintStream err) {
	checkIO();
	setErr0(err);
    }

    private static void checkIO() {
        if (security != null)
	    security.checkPermission(new RuntimePermission("setIO"));
    }

    private static native void setIn0(InputStream in);
    private static native void setOut0(PrintStream out);
    private static native void setErr0(PrintStream err);

    /**
     * Sets the System security.
     *
     * <p> If there is a security manager already installed, this method first
     * calls the security manager's <code>checkPermission</code> method
     * with a <code>RuntimePermission("setSecurityManager")</code>
     * permission to ensure it's ok to replace the existing
     * security manager.
     * This may result in throwing a <code>SecurityException</code>.
     *
     * <p> Otherwise, the argument is established as the current 
     * security manager. If the argument is <code>null</code> and no 
     * security manager has been established, then no action is taken and 
     * the method simply returns. 
     *
     * @param      s   the security manager.
     * @exception  SecurityException  if the security manager has already
     *             been set and its <code>checkPermission</code> method doesn't allow
     *             it to be replaced.
     * @see SecurityManager#checkPermission
     * @see java.lang.RuntimePermission
     */
    public static synchronized void setSecurityManager(SecurityManager s) {
	if (security != null) {
 	    // ask the currently installed security manager if we 
 	    // can replace it.
 	    security.checkPermission(new RuntimePermission
				     ("setSecurityManager"));
	}
	security = s;
	InetAddressCachePolicy.setIfNotSet(InetAddressCachePolicy.FOREVER);
    }

    /**
     * Gets the system security interface.
     *
     * @return  if a security manager has already been established for the
     *          current application, then that security manager is returned;
     *          otherwise, <code>null</code> is returned.
     */
    public static SecurityManager getSecurityManager() {
	return security;
    }

    /**
     * Returns the current time in milliseconds.
     * <p>
     * See the description of the class <code>Date</code> for a discussion 
     * of slight discrepancies that may arise between "computer 
     * time" and coordinated universal time (UTC). 
     *
     * @return  the difference, measured in milliseconds, between the current
     *          time and midnight, January 1, 1970 UTC.
     * @see     java.util.Date
     */
    public static native long currentTimeMillis();

    /** 
     * Copies an array from the specified source array, beginning at the
     * specified position, to the specified position of the destination array.
     * A subsequence of array components are copied from the source 
     * array referenced by <code>src</code> to the destination array 
     * referenced by <code>dst</code>. The number of components copied is 
     * equal to the <code>length</code> argument. The components at 
     * positions <code>srcOffset</code> through 
     * <code>srcOffset+length-1</code> in the source array are copied into 
     * positions <code>dstOffset</code> through 
     * <code>dstOffset+length-1</code>, respectively, of the destination 
     * array. 
     * <p>
     * If the <code>src</code> and <code>dst</code> arguments refer to the 
     * same array object, then the copying is performed as if the 
     * components at positions <code>srcOffset</code> through 
     * <code>srcOffset+length-1</code> were first copied to a temporary 
     * array with <code>length</code> components and then the contents of 
     * the temporary array were copied into positions 
     * <code>dstOffset</code> through <code>dstOffset+length-1</code> of the 
     * destination array. 
     * <p>
     * If <code>dst</code> is <code>null</code>, then a 
     * <code>NullPointerException</code> is thrown.
     * <p>
     * If <code>src</code> is <code>null</code>, then a 
     * <code>NullPointerException</code> is thrown and the destination
     * array is not modified.
     * <p>
     * Otherwise, if any of the following is true, an 
     * <code>ArrayStoreException</code> is thrown and the destination is 
     * not modified: 
     * <ul>
     * <li>The <code>src</code> argument refers to an object that is not an 
     *     array. 
     * <li>The <code>dst</code> argument refers to an object that is not an 
     *     array. 
     * <li>The <code>src</code> argument and <code>dst</code> argument refer to 
     *     arrays whose component types are different primitive types. 
     * <li>The <code>src</code> argument refers to an array with a primitive 
     *     component type and the <code>dst</code> argument refers to an array 
     *     with a reference component type. 
     * <li>The <code>src</code> argument refers to an array with a reference 
     *     component type and the <code>dst</code> argument refers to an array 
     *     with a primitive component type. 
     * </ul>
     * <p>
     * Otherwise, if any of the following is true, an 
     * <code>IndexOutOfBoundsException</code> is 
     * thrown and the destination is not modified: 
     * <ul>
     * <li>The <code>srcOffset</code> argument is negative. 
     * <li>The <code>dstOffset</code> argument is negative. 
     * <li>The <code>length</code> argument is negative. 
     * <li><code>srcOffset+length</code> is greater than 
     *     <code>src.length</code>, the length of the source array. 
     * <li><code>dstOffset+length</code> is greater than 
     *     <code>dst.length</code>, the length of the destination array. 
     * </ul>
     * <p>
     * Otherwise, if any actual component of the source array from 
     * position <code>srcOffset</code> through 
     * <code>srcOffset+length-1</code> cannot be converted to the component 
     * type of the destination array by assignment conversion, an 
     * <code>ArrayStoreException</code> is thrown. In this case, let 
     * <b><i>k</i></b> be the smallest nonnegative integer less than 
     * length such that <code>src[srcOffset+</code><i>k</i><code>]</code> 
     * cannot be converted to the component type of the destination 
     * array; when the exception is thrown, source array components from 
     * positions <code>srcOffset</code> through
     * <code>srcOffset+</code><i>k</i><code>-1</code> 
     * will already have been copied to destination array positions 
     * <code>dstOffset</code> through
     * <code>dstOffset+</code><i>k</I><code>-1</code> and no other 
     * positions of the destination array will have been modified. 
     * (Because of the restrictions already itemized, this
     * paragraph effectively applies only to the situation where both 
     * arrays have component types that are reference types.)
     *
     * @param      src:      the source array.
     * @param      srcpos    start position in the source array.
     * @param      dest      the destination array.
     * @param      destpos   start position in the destination data.
     * @param      length    the number of array elements to be copied.
     * @exception  IndexOutOfBoundsException  if copying would cause
     *               access of data outside array bounds.
     * @exception  ArrayStoreException  if an element in the <code>src</code>
     *               array could not be stored into the <code>dest</code> array
     *               because of a type mismatch.
     * @exception  NullPointerException if either <code>src</code> or 
     *               <code>dst</code> is <code>null</code>.
     */

    //@ requires src != null;
    //@ requires dst != null;
    //@ requires length >= 0
    //@ requires 0 <= src_position
    //@ requires 0 <= dst_position
    //@ requires src_position+length <= \dttfsa(Object[], "identity", src).length;
    //@ requires dst_position+length <= \dttfsa(Object[], "identity", dst).length;
    //@ modifies \dttfsa(Object[], "identity", dst)[*];
    /*@ ensures
        (\forall int i;
           0 <= i-dst_position && i-dst_position < length
          ==>
	   \dttfsa(Object[], "identity", dst)[i] ==
	   \old(\dttfsa(Object[], "identity", src)[src_position+i-dst_position])
	); */
    /*@ ensures
        (\forall int i;
           0 > i-dst_position || i-dst_position >= length
          ==>
	   \dttfsa(Object[], "identity", dst)[i] ==
	   \old(\dttfsa(Object[], "identity", dst)[i])
	); */

    public static native void arraycopy(Object src, int src_position,
                                        Object dst, int dst_position,
                                        int length);

    /**
     * Returns the same hashcode for the given object as
     * would be returned by the default method hashCode(),
     * whether or not the given object's class overrides
     * hashCode().
     * The hashcode for the null reference is zero.
     *
     * @since   JDK1.1
     */
    public static native int identityHashCode(Object x);

    /**
     * System properties. The following properties are guaranteed to be defined:
     * <dl>
     * <dt>java.version		<dd>Java version number
     * <dt>java.vendor		<dd>Java vendor specific string
     * <dt>java.vendor.url	<dd>Java vendor URL
     * <dt>java.home		<dd>Java installation directory
     * <dt>java.class.version	<dd>Java class version number
     * <dt>java.class.path	<dd>Java classpath
     * <dt>os.name		<dd>Operating System Name
     * <dt>os.arch		<dd>Operating System Architecture
     * <dt>os.version		<dd>Operating System Version
     * <dt>file.separator	<dd>File separator ("/" on Unix)
     * <dt>path.separator	<dd>Path separator (":" on Unix)
     * <dt>line.separator	<dd>Line separator ("\n" on Unix)
     * <dt>user.name		<dd>User account name
     * <dt>user.home		<dd>User home directory
     * <dt>user.dir		<dd>User's current working directory
     * </dl>
     */

    //@ invariant props.keyType == \type(String)
    //@ invariant props.elementType == \type(String)
    private static /*@non_null*/ Properties props;
    private static native Properties initProperties(Properties props);

    /**
     * Determines the current system properties. 
     * <p>
     * First, if there is a security manager, its 
     * <code>checkPropertiesAccess</code> method is called with no 
     * arguments. This may result in a security exception. 
     * <p>
     * The current set of system properties for use by the 
     * {@link #getProperty(String)} method is returned as a 
     * <code>Properties</code> object. If there is no current set of 
     * system properties, a set of system properties is first created and 
     * initialized. This set of system properties always includes values 
     * for the following keys: 
     * <table>
     * <tr><th>Key</th>
     *     <th>Description of Associated Value</th></tr>
     * <tr><td><code>java.version</code></td>
     *     <td>Java Runtime Environment version</td></tr>
     * <tr><td><code>java.vendor</code></td>
     *     <td>Java Runtime Environment vendor</td></tr
     * <tr><td><code>java.vendor.url</code></td>
     *     <td>Java vendor URL</td></tr>
     * <tr><td><code>java.home</code></td>
     *     <td>Java installation directory</td></tr>
     * <tr><td><code>java.vm.specification.version</code></td>
     *     <td>Java Virtual Machine specification version</td></tr>
     * <tr><td><code>java.vm.specification.vendor</code></td>
     *     <td>Java Virtual Machine specification vendor</td></tr>
     * <tr><td><code>java.vm.specification.name</code></td>
     *     <td>Java Virtual Machine specification name</td></tr>
     * <tr><td><code>java.vm.version</code></td>
     *     <td>Java Virtual Machine implementation version</td></tr>
     * <tr><td><code>java.vm.vendor</code></td>
     *     <td>Java Virtual Machine implementation vendor</td></tr>
     * <tr><td><code>java.vm.name</code></td>
     *     <td>Java Virtual Machine implementation name</td></tr>
     * <tr><td><code>java.specification.version</code></td>
     *     <td>Java Runtime Environment specification  version</td></tr>
     * <tr><td><code>java.specification.vendor</code></td>
     *     <td>Java Runtime Environment specification  vendor</td></tr>
     * <tr><td><code>java.specification.name</code></td>
     *     <td>Java Runtime Environment specification  name</td></tr>
     * <tr><td><code>java.class.version</code></td>
     *     <td>Java class format version number</td></tr>
     * <tr><td><code>java.class.path</code></td>
     *     <td>Java class path</td></tr>
     * <tr><td><code>os.name</code></td>
     *     <td>Operating system name</td></tr>
     * <tr><td><code>os.arch</code></td>
     *     <td>Operating system architecture</td></tr>
     * <tr><td><code>os.version</code></td>
     *     <td>Operating system version</td></tr>
     * <tr><td><code>file.separator</code></td>
     *     <td>File separator ("/" on UNIX)</td></tr>
     * <tr><td><code>path.separator</code></td>
     *     <td>Path separator (":" on UNIX)</td></tr>
     * <tr><td><code>line.separator</code></td>
     *     <td>Line separator ("\n" on UNIX)</td></tr>
     * <tr><td><code>user.name</code></td>
     *     <td>User's account name</td></tr>
     * <tr><td><code>user.home</code></td>
     *     <td>User's home directory</td></tr>
     * <tr><td><code>user.dir</code></td>
     *     <td>User's current working directory</td></tr>
     * </table>
     * <p>
     * Note that even if the security manager does not permit the 
     * <code>getProperties</code> operation, it may choose to permit the 
     * {@link #getProperty(String)} operation.
     *
     * @exception  SecurityException  if a security manager exists and its  
     *             <code>checkPropertiesAccess</code> method doesn't allow access 
     *              to the system properties.
     * @see        java.lang.SecurityException
     * @see        java.lang.SecurityManager#checkPropertiesAccess()
     * @see        java.util.Properties
     */
    //@ ensures \result!=null
    public static Properties getProperties() {
	if (security != null) {
	    security.checkPropertiesAccess();
	}
	return props;
    }

    /**
     * Sets the system properties to the <code>Properties</code> 
     * argument. 
     * <p>
     * First, if there is a security manager, its 
     * <code>checkPropertiesAccess</code> method is called with no 
     * arguments. This may result in a security exception. 
     * <p>
     * The argument becomes the current set of system properties for use 
     * by the {@link #getProperty(String)} method. If the argument is 
     * <code>null</code>, then the current set of system properties is 
     * forgotten. 
     *
     * @param      props   the new system properties.
     * @exception  SecurityException  if a security manager exists and its  
     *             <code>checkPropertiesAccess</code> method doesn't allow access 
     *              to the system properties.
     * @see        java.lang.Properties
     * @see        java.lang.SecurityException
     * @see        java.lang.SecurityManager#checkPropertiesAccess()
     */
    //@ requires props!=null  // Javadoc spec is wrong!!
    //@ requires props.keyType == \type(String)
    //@ requires props.elementType == \type(String)
    public static void setProperties(Properties props) {
	if (security != null) {
	    security.checkPropertiesAccess();
	}
	System.props = props;
    }
    
    /**
     * Gets the system property indicated by the specified key. 
     * <p>
     * First, if there is a security manager, its 
     * <code>checkPropertyAccess</code> method is called with the key as 
     * its argument. This may result in a SecurityException. 
     * <p>
     * If there is no current set of system properties, a set of system 
     * properties is first created and initialized in the same manner as 
     * for the <code>getProperties</code> method. 
     *
     * @param      key   the name of the system property.
     * @return     the string value of the system property,
     *             or <code>null</code> if there is no property with that key.
     * @exception  SecurityException  if a security manager exists and its  
     *             <code>checkPropertyAccess</code> method doesn't allow access 
     *              to the specified system property.
     * @see        java.lang.SecurityException
     * @see        java.lang.SecurityManager#checkPropertyAccess(java.lang.String)
     * @see        java.lang.System#getProperties()
     */
    public static String getProperty(/*@non_null*/ String key) {
	if (security != null) {
	    security.checkPropertyAccess(key);
	}
	return props.getProperty(key);
    }
    
    /**
     * Gets the system property indicated by the specified key. 
     * <p>
     * First, if there is a security manager, its 
     * <code>checkPropertyAccess</code> method is called with the 
     * <code>key</code> as its argument. 
     * <p>
     * If there is no current set of system properties, a set of system 
     * properties is first created and initialized in the same manner as 
     * for the <code>getProperties</code> method. 
     *
     * @param      key   the name of the system property.
     * @param      def   a default value.
     * @return     the string value of the system property,
     *             or the default value if there is no property with that key.
     * @exception  SecurityException  if a security manager exists and its  
     *             <code>checkPropertyAccess</code> method doesn't allow access 
     *              to the specified system property.
     * @see        java.lang.SecurityManager#checkPropertyAccess(java.lang.String)
     * @see        java.lang.System#getProperties()
     */
    //@ ensures def!=null ==> \result!=null
    public static String getProperty(/*@non_null*/ String key, String def) {
	if (security != null) {
	    security.checkPropertyAccess(key); 
	}
	return props.getProperty(key, def);
    }
    
    /**
     * Sets the system property indicated by the specified key. 
     * <p>
     * First, if a security manager exists, its 
     * <code>SecurityManager.checkPermission</code> method
     * is called with a <code>PropertyPermission(key, "write")</code>
     * permission. This may result in a SecurityException being thrown.
     * If no exception is thrown, the specified property is set to the given
     * value.
     * <p>
     *
     * @param      key   the name of the system property.
     * @param      value the value of the system property.
     * @return     the previous value of the system property,
     *             or <code>null</code> if it did not have one.
     * @exception  SecurityException  if a security manager exists and its  
     *             <code>checkPermission</code> method doesn't allow 
     *             setting of the specified property.
     * @see        java.lang.System#getProperty(java.lang.String)
     * @see        java.lang.System#getProperty(java.lang.String, java.lang.String)
     * @see        java.util.PropertyPermission
     * @see        SecurityManager#checkPermission
     * @since      JDK1.2
     */
    public static String setProperty(/*@non_null*/ String key,
				     /*@non_null*/ String value) {
	if (security != null)
	    security.checkPermission(new PropertyPermission(key, "write"));
	return (String) props.put(key, value);
    }
    
    /**
     * Gets an environment variable. An environment variable is a
     * system-dependent external variable that has a string value.
     *
     * @deprecated The preferred way to extract system-dependent information
     *             is the system properties of the
     *             <code>java.lang.System.getProperty</code> methods and the
     *             corresponding <code>get</code><em>TypeName</em> methods of
     *             the <code>Boolean</code>, <code>Integer</code>, and
     *             <code>Long</code> primitive types.  For example:
     * <blockquote><pre>
     *     String classPath = System.getProperty("java.class.path",".");
     * <br>
     *     if (Boolean.getBoolean("myapp.exper.mode"))
     *         enableExpertCommands();
     * </pre></blockquote>
     * 
     * @param  the name of the environment variable.
     * @return the value of the variable, or <code>null</code> if the variable
     *           is not defined.
     * @see    java.lang.Boolean#getBoolean(java.lang.String)
     * @see    java.lang.Integer#getInteger(java.lang.String)
     * @see    java.lang.Integer#getInteger(java.lang.String, int)
     * @see    java.lang.Integer#getInteger(java.lang.String, java.lang.Integer)
     * @see    java.lang.Long#getLong(java.lang.String)
     * @see    java.lang.Long#getLong(java.lang.String, long)
     * @see    java.lang.Long#getLong(java.lang.String, java.lang.Long)
     * @see    java.lang.System#getProperties()
     * @see    java.lang.System#getProperty(java.lang.String)
     * @see    java.lang.System#getProperty(java.lang.String, java.lang.String)
     */
    public static String getenv(String name) {
	throw new Error("getenv no longer supported, use properties and -D instead: " + name);
    }   //@ nowarn Exception;

    /**
     * Terminates the currently running Java Virtual Machine. The 
     * argument serves as a status code; by convention, a nonzero status 
     * code indicates abnormal termination. 
     * <p>
     * This method calls the <code>exit</code> method in class 
     * <code>Runtime</code>. This method never returns normally. 
     * <p>
     * The call <code>System.exit(n)</code> is effectively equivalent to 
     * the call:
     * <blockquote><pre>
     * Runtime.getRuntime().exit(n)
     * </pre></blockquote>
     *
     * @param      status   exit status.
     * @throws  SecurityException
     *        if a security manager exists and its <code>checkExit</code> 
     *        method doesn't allow exit with the specified status.
     * @see        java.lang.Runtime#exit(int)
     */
    //@ ensures false
    public static void exit(int status) {
	Runtime.getRuntime().exit(status);
    }

    /**
     * Runs the garbage collector.
     * <p>
     * Calling the <code>gc</code> method suggests that the Java Virtual 
     * Machine expend effort toward recycling unused objects in order to 
     * make the memory they currently occupy available for quick reuse. 
     * When control returns from the method call, the Java Virtual 
     * Machine has made a best effort to reclaim space from all discarded 
     * objects.
     * <p>
     * The call <code>System.gc()</code> is effectively equivalent to the 
     * call:
     * <blockquote><pre>
     * Runtime.getRuntime().gc()
     * </pre></blockquote>
     *
     * @see     java.lang.Runtime#gc()
     */
    public static void gc() {
	Runtime.getRuntime().gc();
    }

    /**
     * Runs the finalization methods of any objects pending finalization.
     * <p>
     * Calling this method suggests that the Java Virtual Machine expend 
     * effort toward running the <code>finalize</code> methods of objects 
     * that have been found to be discarded but whose <code>finalize</code> 
     * methods have not yet been run. When control returns from the 
     * method call, the Java Virtual Machine has made a best effort to 
     * complete all outstanding finalizations. 
     * <p>
     * The call <code>System.runFinalization()</code> is effectively 
     * equivalent to the call:
     * <blockquote><pre>
     * Runtime.getRuntime().runFinalization()
     * </pre></blockquote>
     *
     * @see     java.lang.Runtime#runFinalization()
     */
    public static void runFinalization() {
	Runtime.getRuntime().runFinalization();
    }

    /**
     * Enable or disable finalization on exit; doing so specifies that the
     * finalizers of all objects that have finalizers that have not yet been
     * automatically invoked are to be run before the Java runtime exits.
     * By default, finalization on exit is disabled.
     * 
     * <p>If there is a security manager, 
     * its <code>checkExit</code> method is first called
     * with 0 as its argument to ensure the exit is allowed. 
     * This could result in a SecurityException.
     *
     * @deprecated  This method is inherently unsafe.  It may result in
     * 	    finalizers being called on live objects while other threads are
     *      concurrently manipulating those objects, resulting in erratic
     *	    behavior or deadlock.
     * 
     * @throws  SecurityException
     *        if a security manager exists and its <code>checkExit</code> 
     *        method doesn't allow the exit.
     *
     * @see     java.lang.Runtime#exit(int)
     * @see     java.lang.Runtime#gc()
     * @see     java.lang.SecurityManager#checkExit(int)
     * @since   JDK1.1
     */
    public static void runFinalizersOnExit(boolean value) {
	Runtime.getRuntime().runFinalizersOnExit(value);
    }

    /**
     * Loads a code file with the specified filename from the local file 
     * system as a dynamic library. The filename 
     * argument must be a complete pathname. 
     * <p>
     * The call <code>System.load(name)</code> is effectively equivalent 
     * to the call:
     * <blockquote><pre>
     * Runtime.getRuntime().load(name)
     * </pre></blockquote>
     *
     * @param      filename   the file to load.
     * @exception  SecurityException  if a security manager exists and its  
     *             <code>checkLink</code> method doesn't allow 
     *             loading of the specified dynamic library
     * @exception  UnsatisfiedLinkError  if the file does not exist.
     * @see        java.lang.Runtime#load(java.lang.String)
     * @see        java.lang.SecurityManager#checkLink(java.lang.String)
     */
    public static void load(/*@non_null*/ String filename) {
	Runtime.getRuntime().load0(getCallerClass(), filename);
    }

    /**
     * Loads the system library specified by the <code>libname</code> 
     * argument. The manner in which a library name is mapped to the 
     * actual system library is system dependent.
     * <p>
     * The call <code>System.loadLibrary(name)</code> is effectively 
     * equivalent to the call
     * <blockquote><pre>
     * Runtime.getRuntime().loadLibrary(name)
     * </pre></blockquote>
     *
     * @param      libname   the name of the library.
     * @exception  SecurityException  if a security manager exists and its  
     *             <code>checkLink</code> method doesn't allow 
     *             loading of the specified dynamic library
     * @exception  UnsatisfiedLinkError  if the library does not exist.
     * @see        java.lang.Runtime#loadLibrary(java.lang.String)
     * @see        java.lang.SecurityManager#checkLink(java.lang.String)
     */
    public static void loadLibrary(/*@non_null*/ String libname) {
	Runtime.getRuntime().loadLibrary0(getCallerClass(), libname);
    }

    /**
     * Maps a library name into a platform-specific string representing
     * a native library.
     *
     * @param      libname the name of the library.
     * @return     a platform-dependent native library name.
     * @see        java.lang.System#loadLibrary(java.lang.String)
     * @see        java.lang.ClassLoader#findLibrary(java.lang.String)
     * @since      JDK1.2
     */
    public static native String mapLibraryName(String libname);

    /**
     * The following two methods exist because in, out, and err must be
     * initialized to null.  The compiler, however, cannot be permitted to
     * inline access to them, since they are later set to more sensible values
     * by initializeSystemClass().
     */
    private static InputStream nullInputStream() throws NullPointerException {
	if (currentTimeMillis() > 0)
	    return null;
	throw new NullPointerException();
    }

    private static PrintStream nullPrintStream() throws NullPointerException {
	if (currentTimeMillis() > 0)
	    return null;
	throw new NullPointerException();
    }

    /**
     * Initialize the system class.  Called after thread initialization.
     */
    private static void initializeSystemClass() {
	props = new Properties();
	//@ set props.keyType = \type(String)
	//@ set props.elementType = \type(String)

	initProperties(props);
	FileInputStream fdIn = new FileInputStream(FileDescriptor.in);
	FileOutputStream fdOut = new FileOutputStream(FileDescriptor.out);
	FileOutputStream fdErr = new FileOutputStream(FileDescriptor.err);
	setIn0(new BufferedInputStream(fdIn));
	setOut0(new PrintStream(new BufferedOutputStream(fdOut, 128), true));
	setErr0(new PrintStream(new BufferedOutputStream(fdErr, 128), true));
    }

    /* returns the class of the caller. */ 
    static native Class getCallerClass();
}
