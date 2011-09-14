"Unit tests for XML input/output of MeshValueCollection"

# Copyright (C) 2011 Anders Logg
#
# This file is part of DOLFIN.
#
# DOLFIN is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# DOLFIN is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with DOLFIN. If not, see <http://www.gnu.org/licenses/>.
#
# First added:  2011-09-01
# Last changed: 2011-09-01

import unittest
from dolfin import *

class XMLMeshValueCollection(unittest.TestCase):

    def test_io(self):
        "Test input/output"

        # FIXME: Need to expose MeshValueCollection in Python

        # Create markers and add some data
        mesh = UnitCube(5, 5, 5)
        markers = MeshValueCollection("uint", mesh, 2)
        markers.set_value(1, 1);
        markers.set_value(2, 3);
        markers.set_value(5, 8);
        markers.set_value(13, 21);

        # Write to file
        f = File("XMLMeshValueCollection_test_io.xml")
        f << markers

        #

        # FIXME: Add test here
        self.assertEqual(0, 0)

if __name__ == "__main__":
    unittest.main()
