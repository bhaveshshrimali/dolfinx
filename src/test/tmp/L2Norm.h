// Automatically generated by FFC, the FEniCS Form Compiler, version 0.3.3-dev.
// For further information, go to http://www/fenics.org/ffc/.
// Licensed under the GNU GPL Version 2.

#ifndef __L2NORM_H
#define __L2NORM_H

#include <dolfin/Mesh.h>
#include <dolfin/Cell.h>
#include <dolfin/Point.h>
#include <dolfin/AffineMap.h>
#include <dolfin/FiniteElement.h>
#include <dolfin/FiniteElementSpec.h>
#include <dolfin/BilinearForm.h>
#include <dolfin/LinearForm.h>
#include <dolfin/Functional.h>
#include <dolfin/FEM.h>

namespace dolfin { namespace L2Norm {

/// This class contains the form to be evaluated, including
/// contributions from the interior and boundary of the domain.

class LinearForm : public dolfin::LinearForm
{
public:

  class TestElement;

  class FunctionElement_0;

  class FunctionElement_1;

  LinearForm(Function& w0, Function& w1);
  

  bool interior_contribution() const;

  void eval(real block[], const AffineMap& map) const;

  bool boundary_contribution() const;

  void eval(real block[], const AffineMap& map, unsigned int facet) const;

};

class LinearForm::TestElement : public dolfin::FiniteElement
{
public:

  TestElement() : dolfin::FiniteElement(), tensordims(0), subelements(0)
  {
    // Element is scalar, don't need to initialize tensordims

    // Element is simple, don't need to initialize subelements
  }

  ~TestElement()
  {
    if ( tensordims ) delete [] tensordims;
    if ( subelements )
    {
      for (unsigned int i = 0; i < elementdim(); i++)
        delete subelements[i];
      delete [] subelements;
    }
  }

  inline unsigned int spacedim() const
  {
    return 1;
  }

  inline unsigned int shapedim() const
  {
    return 2;
  }

  inline unsigned int tensordim(unsigned int i) const
  {
    dolfin_error("Element is scalar.");
    return 0;
  }

  inline unsigned int elementdim() const
  {
    return 1;
  }

  inline unsigned int rank() const
  {
    return 0;
  }

  void nodemap(int nodes[], const Cell& cell, const Mesh& mesh) const
  {
    nodes[0] = cell.id();
  }

  void pointmap(Point points[], unsigned int components[], const AffineMap& map) const
  {
    points[0] = map(3.333333333333334e-01, 3.333333333333334e-01);
    components[0] = 0;
  }

  void vertexeval(uint vertex_nodes[], unsigned int vertex, const Mesh& mesh) const
  {
    // FIXME: Temporary fix for Lagrange elements
    vertex_nodes[0] = vertex;
  }

  const FiniteElement& operator[] (unsigned int i) const
  {
    return *this;
  }

  FiniteElement& operator[] (unsigned int i)
  {
    return *this;
  }

  FiniteElementSpec spec() const
  {
    FiniteElementSpec s("Discontinuous Lagrange", "triangle", 0);
    return s;
  }
  
private:

  unsigned int* tensordims;
  FiniteElement** subelements;

};

class LinearForm::FunctionElement_0 : public dolfin::FiniteElement
{
public:

  FunctionElement_0() : dolfin::FiniteElement(), tensordims(0), subelements(0)
  {
    // Element is scalar, don't need to initialize tensordims

    // Element is simple, don't need to initialize subelements
  }

  ~FunctionElement_0()
  {
    if ( tensordims ) delete [] tensordims;
    if ( subelements )
    {
      for (unsigned int i = 0; i < elementdim(); i++)
        delete subelements[i];
      delete [] subelements;
    }
  }

  inline unsigned int spacedim() const
  {
    return 3;
  }

  inline unsigned int shapedim() const
  {
    return 2;
  }

  inline unsigned int tensordim(unsigned int i) const
  {
    dolfin_error("Element is scalar.");
    return 0;
  }

  inline unsigned int elementdim() const
  {
    return 1;
  }

  inline unsigned int rank() const
  {
    return 0;
  }

  void nodemap(int nodes[], const Cell& cell, const Mesh& mesh) const
  {
    nodes[0] = cell.vertexID(0);
    nodes[1] = cell.vertexID(1);
    nodes[2] = cell.vertexID(2);
  }

  void pointmap(Point points[], unsigned int components[], const AffineMap& map) const
  {
    points[0] = map(0.000000000000000e+00, 0.000000000000000e+00);
    points[1] = map(1.000000000000000e+00, 0.000000000000000e+00);
    points[2] = map(0.000000000000000e+00, 1.000000000000000e+00);
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
  }

  void vertexeval(uint vertex_nodes[], unsigned int vertex, const Mesh& mesh) const
  {
    // FIXME: Temporary fix for Lagrange elements
    vertex_nodes[0] = vertex;
  }

  const FiniteElement& operator[] (unsigned int i) const
  {
    return *this;
  }

  FiniteElement& operator[] (unsigned int i)
  {
    return *this;
  }

  FiniteElementSpec spec() const
  {
    FiniteElementSpec s("Lagrange", "triangle", 1);
    return s;
  }
  
private:

  unsigned int* tensordims;
  FiniteElement** subelements;

};

class LinearForm::FunctionElement_1 : public dolfin::FiniteElement
{
public:

  FunctionElement_1() : dolfin::FiniteElement(), tensordims(0), subelements(0)
  {
    // Element is scalar, don't need to initialize tensordims

    // Element is simple, don't need to initialize subelements
  }

  ~FunctionElement_1()
  {
    if ( tensordims ) delete [] tensordims;
    if ( subelements )
    {
      for (unsigned int i = 0; i < elementdim(); i++)
        delete subelements[i];
      delete [] subelements;
    }
  }

  inline unsigned int spacedim() const
  {
    return 3;
  }

  inline unsigned int shapedim() const
  {
    return 2;
  }

  inline unsigned int tensordim(unsigned int i) const
  {
    dolfin_error("Element is scalar.");
    return 0;
  }

  inline unsigned int elementdim() const
  {
    return 1;
  }

  inline unsigned int rank() const
  {
    return 0;
  }

  void nodemap(int nodes[], const Cell& cell, const Mesh& mesh) const
  {
    nodes[0] = cell.vertexID(0);
    nodes[1] = cell.vertexID(1);
    nodes[2] = cell.vertexID(2);
  }

  void pointmap(Point points[], unsigned int components[], const AffineMap& map) const
  {
    points[0] = map(0.000000000000000e+00, 0.000000000000000e+00);
    points[1] = map(1.000000000000000e+00, 0.000000000000000e+00);
    points[2] = map(0.000000000000000e+00, 1.000000000000000e+00);
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
  }

  void vertexeval(uint vertex_nodes[], unsigned int vertex, const Mesh& mesh) const
  {
    // FIXME: Temporary fix for Lagrange elements
    vertex_nodes[0] = vertex;
  }

  const FiniteElement& operator[] (unsigned int i) const
  {
    return *this;
  }

  FiniteElement& operator[] (unsigned int i)
  {
    return *this;
  }

  FiniteElementSpec spec() const
  {
    FiniteElementSpec s("Lagrange", "triangle", 1);
    return s;
  }
  
private:

  unsigned int* tensordims;
  FiniteElement** subelements;

};

LinearForm::LinearForm(Function& w0, Function& w1) : dolfin::LinearForm(2)
{
  // Create finite element for test space
  _test = new TestElement();

  // Add functions
  initFunction(0, w0, new FunctionElement_0());
  initFunction(1, w1, new FunctionElement_1());
}

// Contribution from the interior
bool LinearForm::interior_contribution() const { return true; }

void LinearForm::eval(real block[], const AffineMap& map) const
{
  // Compute coefficients
  const real c0_0 = c[0][0];
  const real c0_1 = c[0][1];
  const real c0_2 = c[0][2];
  const real c1_0 = c[1][0];
  const real c1_1 = c[1][1];
  const real c1_2 = c[1][2];

  // Compute geometry tensors
  const real G0_0_0 = map.det*c0_0*c0_0 + map.det*c1_0*c1_0;
  const real G0_0_1 = map.det*c0_0*c0_1 + map.det*c1_0*c1_1;
  const real G0_0_2 = map.det*c0_0*c0_2 + map.det*c1_0*c1_2;
  const real G0_1_0 = map.det*c0_1*c0_0 + map.det*c1_1*c1_0;
  const real G0_1_1 = map.det*c0_1*c0_1 + map.det*c1_1*c1_1;
  const real G0_1_2 = map.det*c0_1*c0_2 + map.det*c1_1*c1_2;
  const real G0_2_0 = map.det*c0_2*c0_0 + map.det*c1_2*c1_0;
  const real G0_2_1 = map.det*c0_2*c0_1 + map.det*c1_2*c1_1;
  const real G0_2_2 = map.det*c0_2*c0_2 + map.det*c1_2*c1_2;
  const real G1_0_0 = map.det*c0_0*c1_0 + map.det*c1_0*c0_0;
  const real G1_0_1 = map.det*c0_0*c1_1 + map.det*c1_0*c0_1;
  const real G1_0_2 = map.det*c0_0*c1_2 + map.det*c1_0*c0_2;
  const real G1_1_0 = map.det*c0_1*c1_0 + map.det*c1_1*c0_0;
  const real G1_1_1 = map.det*c0_1*c1_1 + map.det*c1_1*c0_1;
  const real G1_1_2 = map.det*c0_1*c1_2 + map.det*c1_1*c0_2;
  const real G1_2_0 = map.det*c0_2*c1_0 + map.det*c1_2*c0_0;
  const real G1_2_1 = map.det*c0_2*c1_1 + map.det*c1_2*c0_1;
  const real G1_2_2 = map.det*c0_2*c1_2 + map.det*c1_2*c0_2;

  // Compute element tensor
  block[0] = 8.333333333333318e-02*G0_0_0 + 4.166666666666659e-02*G0_0_1 + 4.166666666666658e-02*G0_0_2 + 4.166666666666659e-02*G0_1_0 + 8.333333333333318e-02*G0_1_1 + 4.166666666666659e-02*G0_1_2 + 4.166666666666658e-02*G0_2_0 + 4.166666666666659e-02*G0_2_1 + 8.333333333333316e-02*G0_2_2 - 8.333333333333318e-02*G1_0_0 - 4.166666666666659e-02*G1_0_1 - 4.166666666666658e-02*G1_0_2 - 4.166666666666659e-02*G1_1_0 - 8.333333333333318e-02*G1_1_1 - 4.166666666666659e-02*G1_1_2 - 4.166666666666658e-02*G1_2_0 - 4.166666666666659e-02*G1_2_1 - 8.333333333333316e-02*G1_2_2;
}

// No contribution from the boundary
bool LinearForm::boundary_contribution() const { return false; }

void LinearForm::eval(real block[], const AffineMap& map, unsigned int facet) const {}

} }

#endif
