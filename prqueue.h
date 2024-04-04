/// @file prqueue.h
/// @author Rayyan Athar
/// @date November 07, 2023
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Fall 2023

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class prqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;       // stored data for the p-queue can be int or string or double or anything
        bool dup;      // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;    // links to linked list of NODES with duplicate priorities
        NODE* left;    // links to left child
        NODE* right;   // links to right child
    };
    NODE* root; // pointer to root node of the BST
    int sz;     // # of elements in the prqueue
    NODE* curr; // pointer to next item in prqueue (see begin and next)


    // Helper function takes in a temporary node to traverse through the tree and a stringstream passed by reference that is recursively built to represent the tree
    void toStringHelper(NODE* temp, stringstream& abc) {
        // Base case when the node is null, function returns
        if(temp == nullptr) {
            return;
        }
        // In order traversal of the tree first goes through the left subtree, then takes in the priority and value of the node and any possible links then traverse the right subtree
        toStringHelper(temp->left, abc);      
        abc << temp->priority << " value: " << temp->value << endl;

        NODE* newnode = temp->link;
        while(newnode != nullptr){
            abc << newnode->priority << " value: " << newnode->value << endl;
            newnode = newnode->link;
        }
        toStringHelper(temp->right, abc);
    }

    // Helper function take in a temporary node to traverse through the tree and clear the tree of all its nodes
    void clearHelper(NODE* temp) {
        // Base case when the node is null, function returns
        if(temp == nullptr) {
            return;
        }
        // Post order traversal of the tree first goes through the left subtree, then the right subtree, and then through any links to the last link and deletes the nodes, 
        clearHelper(temp->left);
        clearHelper(temp->right);

        NODE* newNode = temp->link;
        while(newNode != nullptr) {
            NODE* x = newNode->link;
            delete newNode;
            newNode = x;
        }
        delete temp;
    }
    
    // Helper function takes in a temporary node and recursively copies all the node's links and returns that node, function is used in the copyHelper function to copy a node's link
    NODE* linkHelper(NODE* temp) {
        if(temp == nullptr) {
            return nullptr;
        }
        NODE* newNode = new NODE;
        newNode->value = temp->value;
        newNode->priority = temp->priority;
        newNode->dup = newNode->dup;
        newNode->parent = newNode->parent;

        newNode->link = linkHelper(temp->link);
        return newNode;
    }

    // Helper function takes in a temporary node to a tree and recursively copies the entire tree including all nodes' priorities, values and children and returns that tree
    NODE* copyHelper(NODE* temp) {
        if(temp == nullptr) {
            return nullptr;
        }
        // All of the values of the node are copied into a copyNode, including all of the links if possible 
        NODE* copyNode = new NODE;
        copyNode->priority = temp->priority;
        copyNode->value = temp->value;
        copyNode->dup = temp->dup;
        copyNode->parent = temp->parent;

        copyNode->link = linkHelper(temp->link);
        // Pre order traversal of the tree first copies a node and then goes through the left subtree and then the right subtree to complete copy the tree and eturn
        copyNode->left = copyHelper(temp->left);
        copyNode->right = copyHelper(temp->right);

        return copyNode;
    }

    // Helper function takes in two root pointers of two seperate trees and determines whether they are equivalent by returning a boolean value  
    bool equalHelper(NODE* temp1, NODE* temp2) const {

        // If both nodes are null at the same time then true is returned as they are not yet equal, however if only one of them is null at some point and the other is not, it means the trees are not equal and false is returned
        if(temp1 == nullptr && temp2 == nullptr) {
            return true;
        }
        if(temp1 == nullptr || temp2 == nullptr) {
            return false;
        }

        // Uses two nodes to and a while loop to traverse until the end of both tree nodes' link if needed and determines if all link nodes are equivalent
        NODE* abc = temp1->link;
        NODE* xyz = temp2->link;
        while(abc != nullptr && xyz != nullptr) {
            if(abc->value != xyz->value || abc->priority != xyz->priority) {
                return false;
            }
            abc = abc->link;
            xyz = xyz->link;
        }
        if(abc != nullptr || xyz != nullptr) {
            return false;
        }

        // Otherwise checks nodes of each node and traverses through the left subtree and right subtree until the end, and returns false if two nodes are not equal
        if((temp1->value == temp2->value) && (temp1->priority == temp2->priority)) {
            return equalHelper(temp1->left,temp2->left) && equalHelper(temp1->right,temp2->right);
        }else {
           return false; 
        }
    }

public:
    // default constructor: Creates an empty priority queue. O(1)
    prqueue() {
        sz = 0;
        root = nullptr;
        curr = nullptr;
    }
    
    // operator=: Clears "this" tree and then makes a copy of the "other" tree. Sets all member variables appropriately. O(n), where n is total number of nodes in custom BST
    prqueue& operator=(const prqueue& other) {  
        this->clear();
        this->sz = other.sz;
        this->root = copyHelper(other.root);
        return *this;   
    }
    
    // clear: Frees the memory associated with the priority queue but is public. O(n), where n is total number of nodes in custom BST
    void clear() {  
        clearHelper(root);
        root = nullptr;
        sz = 0;
    }
    
    // destructor: Frees the memory associated with the priority queue. O(n), where n is total number of nodes in custom BST
    ~prqueue() {
        clear();      
    }
    
    // enqueue: Inserts the value into the custom BST in the correct location based on priority.  O(logn + m), where n is number of unique nodes in tree and m is number of duplicate priorities
    void enqueue(T value, int priority) {

        // A new temporary node is created that holds the value and priority and all its links are set to nullptr
        NODE* newNode = new NODE;
        newNode->priority = priority;
        newNode->value = value;
        newNode->dup = false;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr;
        newNode->link = nullptr;

        // If the root is null and this is the first node being added into the tree, the root points to the node 
        if(root == nullptr) {
            root = newNode;
            sz++;
            return;
        }
        
        // Otherwise a currNode is created that traverses through the tree until it reaches the end, inserting the node based on its priority into the correct position
        NODE* currNode = root;
        while(currNode != nullptr) {
            // If the new node's priority is less than the traversal node's priority, then the node traverses through the left subtree until a suitable position is found to add the node
            if(newNode->priority < currNode->priority) {
                // Once the leftmost node is found, its left child is set to the new node, and the new node's parent is set to that leftmost node and currNode is set to null to break the loop
                if(currNode->left == nullptr) {
                    currNode->left = newNode;
                    newNode->parent = currNode;
                    currNode = nullptr;
                }
                // Otherwise the node continues traversing through the left subtree
                else {
                    currNode = currNode->left;
                }
            }
            // If the node's priority is greater than the traversal node's priority, then the node traverses through the right subtree until a suitable position is found to add the node
            else if(newNode->priority > currNode->priority){
                // Once the rightmost node is found, its right child is set to the new node, and the new node's parent is set to that rightmost node and currNode is set to null to break the loop
                if(currNode->right == nullptr) {
                    currNode->right = newNode;
                    newNode->parent = currNode;
                    currNode = nullptr;
                }
                // Otherwise the node continues traversing through the right subtree
                else {
                    currNode = currNode->right;
                }
            }
            // If the node's priority is the same as the traversal node's priority, then the node traverses until the end of the node's link to add the node
            else {
                // The newNode's duplicate value is set to true to indicate it is being added as part of a link as it matches with another node's priority
                newNode->dup = true;
                // Loop iterates until the last node in the link is found and its link is then set to the newNode, while the newNode's parent is set to that node and currNode is set to null to break the loop
                while(currNode->link != nullptr) {
                    currNode = currNode->link;
                }
                currNode->link = newNode;
                newNode->parent = currNode;
                currNode = nullptr;
            }
        }  
        // Before returning the size is updated after adding each node
        sz++; 
        return;
    }

    // dequeue: returns the value of the next element in the priority queue and removes the element from the priority queue. O(logn + m), where n is number of unique nodes in tree and m is number of duplicate priorities
    T dequeue() {
        T valueOut{};

        // If the root is null valueOut is returned
        if(root == nullptr) {
            return valueOut;
        }
        // Begin is set to point to the first element in the priority queue, and its value is stored in valueOut
        begin();
        valueOut = curr->value;

        // If curr has a link then:
        if(curr->link != nullptr) {
            // A temporary node is created that points to curr's link, and then its right, left, and parent nodes are set to point the same as curr's
            NODE* temp = curr->link;
            temp->right = curr->right;
            temp->left = curr->left;
            temp->parent = curr->parent;

            // If curr has a parent then:
            if(curr->parent != nullptr) {
                // If curr is its parent's left child, then the new left child becomes that new node
                if(curr == curr->parent->left) {
                    curr->parent->left = temp;
                }
                // Otherwise curr is its parent's right child, and the new right child becomes that new node
                else{
                    curr->parent->right = temp;
                }
            }
            // Otherwise the root is set to point to that new node
            else{
                root = temp;
            }
            // A new node is created that points to curr and is deleted, so that the curr pointer is not lost
            NODE* abc = curr;
            delete abc;
        }
        else {
            // If curr has a right child then:
            if(curr->right != nullptr) {
                // Then curr's right child's parent is set to points to curr's parent itself
                curr->right->parent = curr->parent;

                // And if that parent is not null then:
                if(curr->parent != nullptr) {
                    // If curr is its parent's left child, then the new left child becomes that new right child
                    if(curr == curr->parent->left) {
                        curr->parent->left = curr->right;
                    }
                    // Otherwise curr is its parent's right child, and the new right child becomes that new right child
                    else{
                        curr->parent->right = curr->right;
                    }
                }
                // Otherwise the root is set to point to that new right child
                else{
                    root = curr->right;
                }
            }
            // Otherise curr has a left child and:
            else {
                // And if its parent is not null then:
                if(curr->parent != nullptr) {
                    // If curr is its parent's left child, then the new left child becomes null
                    if(curr == curr->parent->left) {
                        curr->parent->left = nullptr;
                    }
                    // Otherwise curr is its parent's right child, and the new right child becomes null
                    else{
                        curr->parent->right = nullptr;
                    }
                }
                // Otherwise the root is set to point null
                else{
                    root = nullptr;
                }
            }
            // A new node is created that points to curr and is deleted, so that the curr pointer is not lost
            NODE* xyz = curr;
            delete xyz;
        }
        // The size is finally decreased and the value is returned
        sz--;
        return valueOut; 
    }
    
    // Size: Returns the # of elements in the priority queue, 0 if empty. O(1)
    int size() {
        return sz; 
    }

    // begin: Resets internal state for an inorder traversal.  After the call to begin(), the internal state denotes the first inorder node; this ensure that first call to next() function returns the first inorder node value.  O(logn), where n is number of unique nodes in tree
    void begin() {
        // Traverses the curr node to the left most nod(i.e with highest priority)
        curr = root;
        while(curr->left != nullptr) {
            curr = curr->left;
        }
    }

    // next: Uses the internal state to return the next inorder priority, and then advances the internal state in anticipation of future calls.  If a value/priority are in fact returned (via the reference parameter), true is also returned. False is returned when the internal state has reached null, meaning no more values/priorities are available.  This is the end of the inorder traversal. // O(logn), where n is the number of unique nodes in tree
    bool next(T& value, int &priority) {
        // If curr is null the end of the priority queue has been reached and there are not next values to update so false is retuned
        if(curr == nullptr) {
            return false;
        }
        // The value and priority that are passed by refernce are set to curr's value and priority. In this way if curr changes its pointer, value and priority also change their values as they are passed as references
        value = curr->value;
        priority = curr->priority;

        // If curr has any links, curr is set to point to its next link and the function returns true
        if(curr->link != nullptr) {
            curr = curr->link;
            return true;
        }
        // After traversing through any links and duplicate priorities, curr reverses through the link by pointing to the parent until the main priority node is reached that was the beginning of any links, such that is directly connected to the tree 
        while(curr->dup != false) {
            curr = curr->parent;
        }

        // If curr has any right children, it traverse through the right subtree
        if(curr->right != nullptr) {
            curr = curr->right;
            // And if that right subtree has any left children, curr traverses to the leftmost child within that right subtree, then returns true
            while(curr->left != nullptr) {
                curr = curr->left;
            }
            return true;
        }
        // Otherwise if there are no right children, curr traverses up through the parents
        else {
            // A temporary node is created that points to curr's parrent and while loop iterates up the tree until either the root node is reached to traverse throught the main right subtree, or the next immediate node is found with a right subtree
            NODE* tempParent = curr->parent;
            while(tempParent != nullptr && curr == tempParent->right) {
                curr = tempParent;
                tempParent = tempParent->parent;
            }
            // Curr points to its closest parent with a right subtree and if it is null (reached the root node after traversing the right subtree) false is returned
            curr = tempParent;
            if(curr == nullptr) {
                return false;
            }
        }
        return true; 
    }

    // toString: Returns a string of the entire priority queue, in order.  Format:
    string toString() {
        // Stringstream is created and passed into the helper function by reference to recursively build the string of the priority queue and returned as a string
        string str = "";
        stringstream xyz;
        toStringHelper(root, xyz);
        str = xyz.str();
        return str; 
    }
    
    // peek: returns the value of the next element in the priority queue but does not remove the item from the priority queue. O(logn + m), where n is number of unique nodes in tree and m is number of duplicate priorities
    T peek() {
        T valueOut{};
        // Uses the begin fuinction to traverse through the tree to the node with the highest priority and valueOut is set to that node's value and retuned
        begin();
        if(curr != nullptr) {
            valueOut = curr->value;
        }
        return valueOut; 
    }
    
    // ==operator: Returns true if this priority queue as the priority queue passed in as other. Otherwise returns false. O(n), where n is total number of nodes in custom BST
    bool operator==(const prqueue& other) const {
        // If this tree's size is not the same as the other tree's size then false is returned, otherwise the helper function is used to determine whether they are equal or not
        if(this->sz != other.sz) {
            return false;
        }
        return equalHelper(this->root, other.root); 
    }

    // getRoot - Do not edit/change! Used for testing the BST. return the root node for testing.
    void* getRoot() {
        return root;
    }
};
