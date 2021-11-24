// Bst.h - Binary Search Tree IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

    #ifndef BST_H
    #define BST_H

//---------------------------------------------------------------------------------

    #include <iostream>

//---------------------------------------------------------------------------------

    using std::endl;
    using std::cout;

//---------------------------------------------------------------------------------

            /**
             * \class   Bst
             * \brief   A binary search tree class template class of type T
             *
             *  This class stores data in a binary search tree format. Each node contains data
             *  with left and right pointers pointing to their children (or null if they are leaves).
             *
             *  For insertion of new data, the tree will be traversed recursively, starting with the root node
             *  and where a node's left pointer (if data is less than the parent) or a node's right pointer
             *  (if data is greater than the parent) is pointing to null will instead point to the new data.
             *  Data within the tree can be searched for using a depth first algorithm. Inorder, preorder and
             *  postorder recursive traversals are available. The tree can be checked if it is empty and returns
             *  a boolean to the caller.
             *
             * \author  Daniel Dobson
             * \version 01
             *
             * \date    17/05/2020
            */
    template <class T>
    class Bst
    {
            /// Struct of a node
        struct node
        {
                /// Struct constructor
            node():data(),lp(nullptr),rp(nullptr){};
            node(const node&){};
            operator=(const node&){return *this;};
                /// Variable containing data
            T data;
                /// Left pointer of node
            node *lp;
                /// Right pointer of node
            node *rp;
        };


			/// Function pointer to a function with a void return type and CONST parameter reference of type T
        typedef void (*flTyp) (const T&);

        public:

                    /**
                    * 	\brief Default Constructor
                    *
                    * 	A default constructor to set the binary search tree
                    *
                    */
                Bst();

                    /**
                    * 	\brief Destructor
                    *
                    * 	Destroys all elements in binary search tree
                    *
                    *   \post Memory space occupied by each node is deallocated.
                    */
                ~Bst();

                    /**
                    * 	\brief Copy Constructor
                    *
                    *   Initializes a binary search tree object using another object of the binary search tree
                    *   to ensure a deep copy.
                    *
                    *   \param other_Tree - Binary Search Tree to be copied
                    */
                Bst(const Bst<T> &other_Tree);

                    /**
                    * 	\brief Overloaded assignment operator
                    *
                    *   Assigns a new value to initialised object using another object of the binary search tree
                    *   to ensure a deep copy.
                    *
                    *   \param other_Tree - Binary Search Tree to be copied
                    */
                Bst<T>& operator=(const Bst<T> &other_Tree);

                    /**
                    *   \brief Destroys all elements in binary search tree
                    */
                void delete_Tree();

                    /**
                    * 	\brief Inserts data into binary search tree
                    *
                    *   \param loc_Data - Data to be inserted into tree
                    *   \post A new node is created containing the new data and is assigned as the root if
                    *         the root points to NULL or is passed along with the root to the private function of
                    *         the same name until inserted into the binary search tree.
                    */
                void insert_Elem(const T &loc_Data);

                    /**
                    * 	\brief Determines whether binary search tree is empty
                    *
                    *   \post Returns true if the tree is empty; otherwise, returns false.
                    */
                bool is_Empty() const;

                    /**
                    * 	\brief Inorder traversal of the binary search tree
                    *
					*	\param fp - Function pointer
                    *   \post Nodes are printed in an inorder sequence
                    */
                void inOrder_Trav(flTyp fp) const;

                    /**
                    * 	\brief Preorder traversal of the binary search tree
                    *
					*	\param fp - Function pointer
                    *   \post Nodes are printed in a preorder sequence
                    */
                void preOrder_Trav(flTyp fp) const;

                    /**
                    * 	\brief Postorder traversal of the binary search tree
                    *
					*	\param fp - Function pointer
                    *   \post Nodes are printed in a postorder sequence
                    */
                void postOrder_Trav(flTyp fp) const;

                    /**
                    * 	\brief Determines if data provided is in the binary search tree
                    *
					*	\param loc_Data - Search data criteria
                    *   \post Returns true if data is found; otherwise, returns false.
                    */
                bool search_Tree(const T &loc_Data) const;

                    /**
                    * 	\brief Determines if data provided is in the binary search tree
                    *          and if search item is found, the data is returned by passed
                    *          function parameter.
                    *
					*	\param loc_Data - Search data criteria
					*	\param fp - Function pointer
                    *   \post Returns if search item is found; otherwise, returns false.
                    */
                bool search_Retrieve(const T &loc_Data,flTyp fp) const;

        private:

                    /// Root pointer
                node *root;

                    /**
                    * 	\brief Inserts data into binary search tree (PRIVATE FUNCTION)
                    *
                    *   PRIVATE function (called from public function of same name) traverses the
                    *   binary search tree recursively and the parent points to the new node
                    *   using their left pointer (if data is less than the parent) or the right pointer
                    *   (if the data is greater than the parent) ONLY IF either pointer is pointing to NULL.
                    *   Otherwise, the function will continue until the appropriate pointer is pointing to
                    *   NULL.
                    *
                    *   If the new data is already present in the binary search tree a message
                    *   will be displayed and the new data is NOT ADDED to the tree.
                    *
                    *   \param new_Node - New node containing the new data
                    *   \param par_Node - Parent node
                    *   \post The new node containing the data is inserted into the binary search tree if it doesn't already exist.
                    */
                void insert_Elem(node* &new_Node, node* &par_Node);

                    /**
                    * 	\brief Copies binary search tree (PRIVATE FUNCTION)
                    *
                    *   Called by the copy constructor and overloaded assignment operator or recursively called.
                    *   Function makes a copy of the binary tree to which other_Root points using deep copy
                    *
                    *   \param copied_Root - Copied root
                    *   \param other_Root - Other root used for copy
                    *   \post Pointer copied_Root points to the root of the other_Root binary search tree
                    */
                void copy_Tree(node* &copied_Root, node* other_Root);

                    /**
                    * 	\brief Deletes the binary tree to which p points (PRIVATE METHOD)
                    *
                    *   Called by the destructor and overloaded assignment operator (if root is not NULL)
                    *   or recursively called.
                    *
                    *   \param p - Node of which is used to delete the tree from where it points to.
                    *   \post Memory space occupied by each node, in the binary search tree to which p points, is deallocated.
                    */
                void delete_Tree(node* &p);

                    /**
                    * 	\brief Inorder traversal of the binary search tree to which p points
                    *
                    *   Called by the public function of the same name or recursively called.
                    *
					*	\param p - Node to which p points
					*	\param fp - Passed function
                    *   \post Nodes of the binary search tree, to which p points, are printed in inorder sequence.
                    */
                void inOrder(node *p, flTyp fp) const;

                    /**
                    * 	\brief Preorder traversal of the binary search tree to which p points
                    *
                    *   Called by the public function of the same name or recursively called.
                    *
					*	\param p - Node to which p points
					*	\param fp - Passed function
                    *   \post Nodes of the binary search tree, to which p points, are printed in preorder sequence.
                    */
                void preOrder(node *p, flTyp fp) const;

                    /**
                    * 	\brief Postorder traversal of the binary search tree to which p points
                    *
                    *   Called by the public function of the same name or recursively called.
                    *
					*	\param p - Node to which p points
					*	\param fp - Passed function
                    *   \post Nodes of the binary search tree, to which p points, are printed in postorder sequence.
                    */
                void postOrder(node *p, flTyp fp) const;

                    /**
                    * 	\brief Determines if data provided is in the binary search tree
                    *
                    *   Called by the public function of the same name or recursively called.
                    *
					*	\param loc_node - Node to which loc_Node points
					*	\param loc_Data - Search item passed by reference
					*	\param retrieve - True or False if the data is to be returned by function pointer
					*	\param fp - Function pointer
                    *   \post Returns true if data is found; otherwise, returns false.
                    */
                bool search_Tree(const node* loc_node, const T &loc_Data, bool retrieve, flTyp fp) const;

    };

            //CONSTRUCTOR
        template<class T>
        Bst<T>::Bst()
            :root{nullptr}
        {

        }

            //DESTRUCTOR
        template<class T>
        Bst<T>::~Bst()
        {
            delete_Tree(root);
        }

            //COPY CONSTRUCTOR
        template<class T>
        Bst<T>::Bst(const Bst<T> &other_Tree)
            :root{nullptr}
        {
            if(other_Tree.root == nullptr)
                root = nullptr;
            else
                copy_Tree(root, other_Tree.root);
        }

            //OVERLOADED ASSIGNMENT OPERATOR
        template<class T>
        Bst<T> & Bst<T>::operator=(const Bst<T> &other_Tree)
        {
            if(this != &other_Tree)
            {
                if(root != nullptr)
                    delete_Tree(root);

                if(other_Tree.root == nullptr)
                    root = nullptr;
                else
                    copy_Tree(root, other_Tree.root);
            }

            return *this;
        }

            //Destroys all elements in binary search tree
        template<class T>
        void Bst<T>::delete_Tree()
        {
            delete_Tree(root);
        }

            //Determines whether binary search tree is empty
        template<class T>
        bool Bst<T>::is_Empty() const
        {
            return(root == nullptr);
        }

            //Inorder traversal of the binary search tree
        template<class T>
        void Bst<T>::inOrder_Trav(flTyp fp) const
        {
            inOrder(root, fp);
        }

            //Preorder traversal of the binary search tree
        template<class T>
        void Bst<T>::preOrder_Trav(flTyp fp) const
        {
            preOrder(root, fp);
        }

            //Postorder traversal of the binary search tree
        template<class T>
        void Bst<T>::postOrder_Trav(flTyp fp) const
        {
            postOrder(root, fp);
        }

            //Inserts data into binary search tree
        template<class T>
        void Bst<T>::insert_Elem(const T &loc_Data)
        {
                    //Node is created for new data
            node *new_Node;

            new_Node = new node;
            new_Node->data = loc_Data;

                    //Root is assigned as new node if root is NULL
            if(root == nullptr)
                root = new_Node;

                    // Otherwise, new node is inserted using the private function
            else
                insert_Elem(new_Node, root);
        }

            //Determines if data provided is in the binary search tree
        template<class T>
        bool Bst<T>::search_Tree(const T &loc_Data) const
        {
            bool retrieve = false;

                    //Returns message if tree does not exist!
            if(root == nullptr)
            {
                //cout << "Cannot search an empty tree!" << endl; TESTING ONLY
                return false;
            }
                    //Otherwise search tree using private function
            else
                return search_Tree(root,loc_Data, retrieve, nullptr);
        }

        template<class T>
        bool Bst<T>::search_Retrieve(const T &loc_Data,flTyp fp) const
        {
            bool retrieve = true;

            if(root == nullptr)
            {
                //cout << "Cannot search an empty tree!" << endl; TESTING ONLY
                return false;
            }else
                return search_Tree(root, loc_Data, retrieve, fp);
        }


            //PRIVATE - Inserts data into binary search tree
        template<class T>
        void Bst<T>::insert_Elem(node* &new_Node, node* &par_Node)
        {
            if(new_Node->data < par_Node->data)
            {
                    //Parent left pointer points to new node if NULL
                if(par_Node->lp == nullptr)
                   par_Node->lp = new_Node;

                    //Otherwise re-call function.
                else
                    insert_Elem(new_Node,par_Node->lp);
            }
            else
            {
                if(!(new_Node->data == par_Node->data))
                {
                        //Parent right pointer points to new node if NULL
                    if(par_Node->rp == nullptr)
                        par_Node->rp = new_Node;

                        //Otherwise re-call function.
                    else
                        insert_Elem(new_Node,par_Node->rp);
                }
            }
        }

            //PRIVATE - Copies binary search tree
        template<class T>
        void Bst<T>::copy_Tree(node* &copied_Root, node* other_Root)
        {
            if(other_Root == nullptr)
                copied_Root = nullptr;
            else
            {
                    //Create new node to copy to
                copied_Root = new node;
                    //Copy other_Root data into copied_Root
                copied_Root->data = other_Root->data;
                copy_Tree(copied_Root->lp, other_Root->lp);
                copy_Tree(copied_Root->rp, other_Root->rp);
            }
        }

            //PRIVATE - Deletes the binary tree to which p points
        template<class T>
        void Bst<T>::delete_Tree(node* &p)
        {
           if(p != nullptr)
           {
                delete_Tree(p->lp);
                delete_Tree(p->rp);
                delete p;
                p = nullptr;
           }
        }

            //PRIVATE - Inorder traversal of the binary search tree to which p points
        template<class T>
        void Bst<T>::inOrder(node *p, flTyp fp) const
        {
            if(p != nullptr)
            {
                inOrder(p->lp, fp);
                fp(p->data);
                inOrder(p->rp, fp);
            }
        }

            //PRIVATE - Preorder traversal of the binary search tree to which p points
        template<class T>
        void Bst<T>::preOrder(node *p, flTyp fp) const
        {
            if(p != nullptr)
            {
                fp(p->data);
                preOrder(p->lp, fp);
                preOrder(p->rp, fp);
            }
        }

            //PRIVATE - Postorder traversal of the binary search tree to which p points
        template<class T>
        void Bst<T>::postOrder(node *p, flTyp fp) const
        {
            if(p != nullptr)
            {
                postOrder(p->lp, fp);
                postOrder(p->rp, fp);
                fp(p->data);
            }
        }

            //PRIVATE - Determines if data provided is in the binary search tree
        template<class T>
        bool Bst<T>::search_Tree(const node* loc_node, const T &loc_Data, bool retrieve, flTyp fp) const
        {
            static int counter = 0;
            counter++;

                //If node is NULL
            if(loc_node == nullptr)
                return false;

                //If data is EQUAL to data value
            else if(loc_node->data == loc_Data)
            {
                if(retrieve == true)
                    fp(loc_node->data);

                return true;
            }

                //If data value is greater than data in node, go left. re-call function.
            else if (!(loc_node->data < loc_Data))
                return search_Tree(loc_node->lp,loc_Data, retrieve, fp);

                //Otherwise, go right and re-call function.
            else
                return search_Tree(loc_node->rp,loc_Data, retrieve, fp);
        }

//---------------------------------------------------------------------------------
#endif // BST_H
