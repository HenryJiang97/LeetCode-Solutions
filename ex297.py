# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        
        track = []              # Record the track of traverse pointer (For tracing back)
        
        # Add root to string and track list
        if root == None:
            r = "[" + "null"
        else:
            r = "[" + str(root.val)
            track.append(root)
        
        
        while len(track) > 0:
            root = track.pop(0)
            
            # Add left node info
            if root.left == None:
                r += ",null"
            else:
                r = r + "," + str(root.left.val)
                track.append(root.left)
            
            # Add right node info
            if root.right == None:
                r += ",null"
            else:
                r = r + "," + str(root.right.val)
                track.append(root.right)


        r += "]"

        return r
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        
        # If the BT is null, return root node as None
        if data == "[null]":
            return None
        
        # Interpret string to a track list
        d = data[1 : len(data) - 1].split(",")
        track = []

        # Create root node
        root = TreeNode(d.pop(0))
        track.append(root)
        
        while len(d) > 0:
            l = TreeNode(d.pop(0))
            track[0].left = l

            r = TreeNode(d.pop(0))
            track[0].right = r

            
            track.append(l)
            track.append(r)
            track.pop(0)

            
        return root


        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))