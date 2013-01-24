/* Modifications Copyright 2000 by Compaq Computer Corporation */
/*
 * @(#)EscjavaKeyValue.java
 *
 * Copyright 2000 by Compaq Computer Corporation,
 * All rights reserved.
 *
 */

package java.util;

public interface EscjavaKeyValue {
  /**
   ** The type of the object's keys
   **/
  //@ ghost public \TYPE keyType;

  /**
   ** Whether or not the object permits <code>null</code> as a key.
   **/
  //@ ghost public boolean permitsNullKey;

  /**
   ** The type of the object's values
   **/
  //@ ghost public \TYPE elementType;

  /**
   ** Whether or not the object permits <code>null</code> as a value.
   **/
  //@ ghost public boolean permitsNullValue;
}
