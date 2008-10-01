/************************
 A Cocoa DataStructuresFramework
 Copyright (C) 2002  Phillip Morelock in the United States
 http://www.phillipmorelock.com
 Other copyrights for this specific file as acknowledged herein.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *******************************/

//  Deque.h
//  DataStructuresFramework

#import <Foundation/Foundation.h>
#import "Util.h"

/**
 A <a href="http://en.wikipedia.org/wiki/Deque">deque</a> protocol with methods for
 insertion and removal on both ends of a queue.
 
 @todo Add support for methods in NSCoding, NSMutableCopying, and NSFastEnumeration.
 */
@protocol Deque <NSObject>

/**
 Initialize a newly allocated deque by placing in it the objects from an enumerator.
 
 @param anEnumerator An enumerator which provides objects to insert into the queue.
        Objects are inserted in the order received from <code>-nextObject</code>.
 */
- (id) initWithObjectsFromEnumerator:(NSEnumerator*)anEnumerator;

/**
 Add an object to the front of the deque.
 
 @param anObject The object to add to the deque; must not be <code>nil</code>, or an
        <code>NSInvalidArgumentException</code> is raised.
 */
- (void) prependObject:(id)anObject;

/**
 Add a group of objects to the front of the deque.
 
 @param enumerator An enumerator containing objects to add to the front of the deque;
		an <code>NSInvalidArgumentException</code> is raised if <code>nil</code>.
        Objects are prepended in the order in they are provided by <i>enumerator</i>.
 */
- (void) prependObjectsFromEnumerator:(NSEnumerator*)enumerator;

/**
 Add an object to the back of the deque.
 
 @param anObject The object to add to the deque; must not be <code>nil</code>, or an
 <code>NSInvalidArgumentException</code> is raised.
 */
- (void) appendObject:(id)anObject;

/**
 Add a group of objects to the back of the deque.
 
 @param enumerator An enumerator containing objects to add to the back of the deque;
		an <code>NSInvalidArgumentException</code> is raised if <code>nil</code>.
		Objects are appended in the order in they are provided by <i>enumerator</i>.
 */
- (void) appendObjectsFromEnumerator:(NSEnumerator*)enumerator;

/**
 Examine the first object in the deque without removing it.
 
 @return The first object in the deque, or <code>nil</code> if the deque is empty.
 */
- (id) firstObject;

/**
 Examine the last object in the deque without removing it.
 
 @return The last object in the deque, or <code>nil</code> if the deque is empty.
 */
- (id) lastObject;

/**
 Returns an array containing the objects in this deque, ordered from front to back.
 
 @return An array containing the objects in this deque. If the deque is empty, the
		 array is also empty.
 */
- (NSArray*) allObjects;

/**
 Remove and return the first object in the deque.
 
 @return The first object in the deque, or <code>nil</code> if the deque is empty.
 */
- (void) removeFirstObject;

/**
 Remove and return the last object in the deque.
 
 @return The last object in the deque, or <code>nil</code> if the deque is empty.
 */
- (void) removeLastObject;

/**
 Returns an NSArray containing the objects in this deque in front-to-back order.
 @return An array which contains the objects in this deque.
 */
- (void) removeAllObjects;

/**
 Determines if a deque contains a given object, matched using <code>isEqual:</code>.
 
 @param anObject The object to test for membership in the deque.
 */
- (BOOL) containsObject:(id)anObject;

/**
 Determines if a deque contains a given object, matched using the == operator.
 
 @param anObject The object to test for membership in the deque.
 */
- (BOOL) containsObjectIdenticalTo:(id)anObject;

/**
 Returns the number of objects currently in the deque.
 
 @return The number of objects currently in the deque.
 */
- (NSUInteger) count;

@end