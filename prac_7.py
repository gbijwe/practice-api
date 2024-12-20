from pomegranate import *

a = DiscreteDistribution({'1': 1./10, '0': 9./10})

# The door the prize is behind is also completely random
c = DiscreteDistribution({'1': 1./2, '0': 1./2})

b = ConditionalProbabilityTable(
        [[ '0', '0', 0.1 ],
         [ '0', '1', 0.9 ],
         [ '1', '0', 0.6 ],
         [ '1', '1', 0.4 ]],[a])

d = ConditionalProbabilityTable(
        [[ '0', '0', 0.4 ],
         [ '0', '1', 0.6 ],
         [ '1', '0', 0.7 ],
         [ '1', '1', 0.3 ]],[c])

e = ConditionalProbabilityTable(
        [[ '0', '0', 0.8 ],
         [ '0', '1', 0.2 ],
         [ '1', '0', 0.9 ],
         [ '1', '1', 0.1 ]],[b])

h = ConditionalProbabilityTable(
        [[ '0', '0', 0.3 ],
         [ '0', '1', 0.7 ],
         [ '1', '0', 0.5 ],
         [ '1', '1', 0.5 ]],[e])

i = ConditionalProbabilityTable(
        [[ '0', '0', 0.3 ],
         [ '0', '1', 0.7 ],
         [ '1', '0', 0.2 ],
         [ '1', '1', 0.8 ]],[e])

f = ConditionalProbabilityTable(
        [[ '0', '0', '1', 0.0 ],
         [ '0', '1', '1', 0.2 ],
         [ '1', '0', '1', 0.4 ],
         [ '1', '1', '1', 0.7 ],
         [ '0', '0', '0', 1.0 ],
         [ '0', '1', '0', 0.8 ],
         [ '1', '0', '0', 0.6 ],
         [ '1', '1', '0', 0.3 ]],[b,d])

g = ConditionalProbabilityTable(
        [[ '0', '0', 0.9 ],
         [ '0', '1', 0.1 ],
         [ '1', '0', 0.1 ],
         [ '1', '1', 0.9 ]],[f])

A = State(a, name="A")
B = State(b, name="B")
C = State(c, name="C")
D = State(d, name="D")
E = State(e, name="E")
F = State(f, name="F")
G = State(g, name="G")
H = State(h, name="H")
I = State(i, name="I")


model = BayesianNetwork("DS251_A2_Q5-2")

# Add the three states to the network
model.add_states(A, B, C, D, E, F, G, H, I)


model.add_edge(A, B)
model.add_edge(B, E)
model.add_edge(B, F)
model.add_edge(C, D)
model.add_edge(D, F)
model.add_edge(E, H)
model.add_edge(E, I)
model.add_edge(F, G)

model.bake()
