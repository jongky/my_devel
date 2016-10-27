#!/usr/bin/env python
import unittest
from mounttab2 import parse_mounts

class TestMount(unittest.TestCase):
    """
    Our basic test class
    """

    def test_parsemount(self):
        """
        The actual test.
        Any method which starts with ``test_`` will considered as a test case.
        """
        result = parse_mounts()
        self.assertIsInstance(result, list)
        self.assertIsInstance(result[0], tuple)

    def test_rootext4(self):
        """
        Test to find root filesystem
        """
        result = parse_mounts()
        for line in result:
            if line[1] == '/' and line[2] != 'rootfs':
                self.assertEqual(line[2], 'ext4')


if __name__ == '__main__':
    unittest.main()