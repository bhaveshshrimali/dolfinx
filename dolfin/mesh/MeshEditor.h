// Copyright (C) 2006-2012 Anders Logg
//
// This file is part of DOLFIN (https://www.fenicsproject.org)
//
// SPDX-License-Identifier:    LGPL-3.0-or-later

#pragma once

#include "CellType.h"
#include "Mesh.h"
#include <vector>

namespace dolfin
{

class Point;

/// A simple mesh editor for creating simplicial meshes in 1D, 2D
/// and 3D.

class MeshEditor
{
public:
  /// Constructor
  MeshEditor();

  /// Destructor
  ~MeshEditor();

  /// Open mesh of given cell type, topological and geometrical dimension
  ///
  /// @param    mesh (_Mesh_)
  ///         The mesh to open.
  /// @param    type (CellType::Type)
  ///         Cell type.
  /// @param    tdim (std::size_t)
  ///         The topological dimension.
  /// @param    gdim (std::size_t)
  ///         The geometrical dimension.
  /// @param    degree (std::size_t)
  ///         The polynomial degree.
  void open(Mesh& mesh, CellType::Type type, std::size_t tdim, std::size_t gdim,
            std::size_t degree = 1);

  /// Initialise entities in MeshGeometry
  ///
  /// Create required Edges and Faces for the current polynomial degree
  /// in the mesh topology, so that points can be added for them.
  /// In order to initialise entities, cells must all be added first.
  ///
  void init_entities();

  /// Specify number of vertices (distributed version)
  ///
  /// @param num_local_vertices (std::size_t)
  ///         The number of vertices on this process.
  /// @param num_global_vertices (std::size_t)
  ///         The number of vertices in distributed mesh.
  ///
  /// @code{.cpp}
  ///
  ///         Mesh mesh;
  ///         MeshEditor editor;
  ///         editor.open(mesh, 2, 2);
  ///         editor.init_vertices(4, 8);
  /// @endcode
  void init_vertices_global(std::size_t num_local_vertices,
                            std::size_t num_global_vertices);

  /// Specify number of cells (distributed version)
  ///
  /// @param num_local_cells (std::size_t)
  ///         The number of local cells.
  /// @param num_global_cells (std::size_t)
  ///         The number of cells in distributed mesh.
  ///
  /// @code{.cpp}
  ///
  ///         Mesh mesh;
  ///         MeshEditor editor;
  ///         editor.open(mesh, 2, 2);
  ///         editor.init_cells(2, 6);
  /// @endcode
  void init_cells_global(std::size_t num_local_cells,
                         std::size_t num_global_cells);

  /// Add vertex v at given point p
  ///
  /// @param    local_index (std::size_t)
  ///         The vertex (local index).
  /// @param    global_index (std::size_t)
  ///         The vertex (global_index).
  /// @param    p (_Point_)
  ///         The point.
  void add_vertex(std::size_t local_index, std::size_t global_index,
                  const Point& p);

  /// Local add
  void add_vertex(std::size_t index, const Point& p);

  /// Add a point in a given entity of dimension entity_dim
  void add_entity_point(std::size_t entity_dim, std::size_t order,
                        std::size_t index, const Point& p);

  /// Add cell with given vertices
  ///
  /// @param     local_index (std::size_t)
  ///         The cell (index).
  /// @param    global_index (std::size_t)
  ///         The global (user) cell index.
  /// @param    v (std::vector<std::size_t>)
  ///         The vertex indices (local indices)
  template <typename T>
  void add_cell(std::size_t local_index, std::size_t global_index, const T& v)
  {
    // dolfin_assert(v.size() == _tdim + 1);

    // Check vertices
    check_vertices(v);

    // Add cell
    add_cell_common(local_index, _tdim);

    // Set data
    _mesh->_topology(_tdim, 0).set(local_index, v);
    _mesh->_topology.set_global_index(_tdim, local_index, global_index);
  }

  /// Local add
  template <typename T>
  void add_cell(std::size_t index, const T& v)
  {
    add_cell(index, index, v);
  }

  /// Close mesh, finish editing, and order entities locally
  ///
  /// @param    order (bool)
  ///         Order entities locally if true. Default values is true.
  ///
  /// @code{.cpp}
  ///
  ///         MeshEditor editor;
  ///         editor.open(mesh, 2, 2);
  ///         ...
  ///         editor.close()
  /// @endcode
  void close(bool order = true);

private:
  // Friends
  friend class TetrahedronCell;

  // Add vertex, common part
  void add_vertex_common(std::size_t v, std::size_t dim);

  // Add cell, common part
  void add_cell_common(std::size_t v, std::size_t dim);

  // Compute boundary indicators (exterior facets)
  void compute_boundary_indicators();

  // Clear all data
  void clear();

  // Check that vertices are in range
  template <typename T>
  void check_vertices(const T& v) const
  {
    for (std::size_t i = 0; i < v.size(); ++i)
    {
      if (_num_vertices > 0 && v[i] >= _num_vertices)
      {
        dolfin_error("MeshEditor.cpp", "add cell using mesh editor",
                     "Vertex index (%d) out of range [0, %d)", v[i],
                     _num_vertices);
      }
    }
  }

  // The mesh
  Mesh* _mesh;

  // Topological dimension
  std::size_t _tdim;

  // Geometrical (Euclidean) dimension
  std::size_t _gdim;

  // Number of vertices
  std::size_t _num_vertices;

  // Number of cells
  std::size_t _num_cells;

  // Next available vertex
  std::size_t next_vertex;

  // Next available cell
  std::size_t next_cell;

  // Temporary storage for local cell data
  std::vector<std::size_t> _vertices;
};
}
