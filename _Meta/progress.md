# Progress Tracker

## Current Focus
Memory model and ownership — stack, heap, raw pointers, RAII,
constructors, destructors, unique_ptr. Foundation layer for all
C++ work. Next session: reinforce unique_ptr, introduce move
semantics, begin ownership rules.

---

## Standing Code Instructions (All Sessions)

**Initialization vs Assignment — Default Protocol:**
When providing code assistance or examples, always demonstrate the
initialization method alongside or instead of the assignment method,
unless the assignment method is genuinely best practice for that
specific case — in which case, explain why.

Initialization method (preferred, modern C++):
  `int x{42};`           // brace initialization — always prefer this
  `MyClass obj{a, b};`   // aggregate and constructor init
  `auto x = int{42};`    // explicit type with brace init

Assignment method:
  `int x = 42;`           // copy/assignment init

Why initialization is preferred:
  1. Prevents narrowing conversions at compile time
     (`int x{3.14}` is a compile error — catches bugs brace init
      that `int x = 3.14` silently allows)
  2. Works uniformly across all types — primitives, aggregates,
     classes, initializer lists
  3. Most explicit about intent — preferred in modern C++17/20/23

When assignment method IS the right answer — state it explicitly:
  - `auto x = someFunction();` where the return type is deduced
    and brace init would invoke std::initializer_list overload instead
  - Legacy interface code where brace init is not supported
  - When copy semantics are the explicit intent

This rule applies to every code example, demo, and kinesthetic
exercise unless Aaron explicitly asks otherwise for a specific case.

---

## Final Project: Committed
**Lightweight Neural Network Inference Engine**
Decision made: 2026-05-09. No need to revisit at checkpoint.
Every assignment from this point forward is a construction phase
of this system. By Jul 28 checkpoint, most components will already
exist. The checkpoint submission is integration status, not a
first draft.

---

## Course Training Map — CSC275 C++ Programming II

**Course window:** May 2026 – August 2026
**Standard:** Modern C++ (C++17/20/23) throughout.
**Grade compliance rule:** Raw new/delete and raw pointer parameters
written as required for UAT rubrics. In mastery sessions, immediately
rewritten to modern equivalents. Know both. Defend the distinction
at senior-review level.

**Critical naming constraint (assign_01 and 02):**
The AI architecture mapping is STRUCTURAL UNDERSTANDING, not a
renaming scheme. Required UAT class and method names must be preserved
exactly. AI-parallel methods and properties are ADDED ON TOP of
required elements. The structural pattern is what we learn from;
the theme is what the professor grades.

**Governing principle:** Every assignment IS a component of the final
NN inference engine. By the final project due date, most subsystems
will already have been built and graded.

---

### The System Architecture — Assignment Build Order

```
assign_01  → Layer base class pattern    (the skeleton)
assign_02  → Abstract interfaces pattern (the compute)
assign_03  → Safe inference pipeline     (the armor)
assign_04a → Weight serialization        (the memory)
assign_04b → First integrated prototype  (the prototype)
assign_05  → Robust data loader          (the input stage)
assign_06  → Tensor operations library   (the math engine — rubric validated)
assign_08  → Memory layout + smart ptr   (the foundation)
assign_09  → Ownership model             (the discipline)
assign_10  → Graph traversal w/ classes  (the execution engine)
assign_11  → Async training loop         (the runtime)
Lambda     → Data pipeline transforms    (the functional layer)
Final      → Complete integrated system  (the product)
```

---

### Phase 1 — Memory Foundation (Active Now)
**Window:** May 9 – May 19 | **Prerequisite for everything**

| Topic | AI Application |
|-------|---------------|
| Stack vs Heap | All ML tensors live on the heap; ownership rules prevent leaks in long-running inference servers |
| Raw pointer failure modes | C APIs (CUDA, BLAS, cuDNN) hand raw pointers at the boundary — know the failure modes to survive the interface |
| RAII pattern | GPU memory, file handles, mutex locks — all RAII in production ML code |
| Constructors and Destructors | Layer init and teardown; destructor timing governs resource release in inference pipelines |
| std::unique_ptr | Exclusive ownership of neural network layers |
| Move semantics | Transferring large tensors between pipeline stages without copying |

---

### Phase 2 — assign_01: OOP I
**Due:** May 19 | **Points:** 40 | **AI Component: Layer Architecture Pattern**

**Rubric breakdown:**
- 15pts: Functional character generator using OOP, full understanding, no/few errors
- 10pts: Over-commented, naming conventions, readability, proper formatting
- 10pts: User-friendly interface, readable output, first-time user clarity
- 5pts: CSC275-1 — declare variables using appropriate data-types & scope

**Required names — must be exact (rubric checks OOP compliance):**
- Class: `Character` (public property `Name`, private property `Health`)
- Class: `Ninja : Character` (method `ThrowStars()` → outputs "I am throwing stars!")
- Class: `Pirate : Character` (method `UseSword()` → outputs "I am Swooshing my Sword!")
- Constructors in both subclasses initializing all properties
- Intro method in main.cpp, called from main()
- Comment every line except cout (unless at top of block)

**AI parallel (added on top, not replacing):**
- The `Character / Ninja / Pirate` hierarchy IS the `Layer / DenseLayer / ConvLayer` pattern
- `ThrowStars()` and `UseSword()` ARE specializations of a forward() computation
- `Health` (private, encapsulated) maps exactly to activation state — private internal data
- Constructor initialization of all properties IS layer initialization
- "More features = better grade" — add AI-inspired extended methods alongside required ones

**Max points checklist:**
- [ ] All 3 classes present with exact required names
- [ ] ThrowStars outputs exact string
- [ ] UseSword outputs exact string
- [ ] Both subclass constructors initialize all properties
- [ ] Health is private in Character
- [ ] Name is public in Character
- [ ] Intro method in main.cpp called from main
- [ ] Every non-cout line commented
- [ ] Strong UX with clear output

---

### Phase 3 — assign_02: OOP II
**Due:** May 26 | **Points:** 25 | **AI Component: Abstract Interface Pattern**

**Rubric breakdown:**
- 5pts: Functional character generator using OOP, no/few errors
- 5pts: Over-commented, naming conventions, readability
- 5pts: Great UX, user-friendly, readable output
- 5pts: CSC275-8 — Derive new classes from base and abstract classes (threshold 3.0)
- 5pts: CSC275-9 — Use polymorphism in applications (threshold 3.0)

**Required structure — must be exact:**
- Class: `GameStructure` with pure virtual `Help()` (void, no parameters)
- `Character` inherits from `GameStructure`, overrides `Help()`
- `Ninja` and `Pirate` each override `Help()` with character-specific output
- `Health` private in `Character` with getter and setter
- Setter: if new value < 0, set to 0, display "Character has Expired..."
- Overloaded `Talk(string name, string stuffToSay)` — both Talk methods say name then stuff
- `virtual int attack()` in Character returns 10
- `override int attack()` in both Ninja and Pirate returns 25

**Inheritance chain:**
`GameStructure` (pure virtual Help) → `Character` (overrides Help, has Talk×2, virtual attack)
  → `Ninja` (overrides attack, overrides Help, ThrowStars)
  → `Pirate` (overrides attack, overrides Help, UseSword)

**AI parallel:**
- `GameStructure` → abstract interface pattern (same as abstract Optimizer, abstract LossFunction)
- Pure virtual Help() → pure virtual forward() — defines the contract, forces derived classes to implement
- Overloaded Talk() → overloaded compute(float) / compute(vector<float>) — scalar vs batch
- virtual/override attack() with different return values → virtual forward() with specialized computation
- Health floor at zero → ReLU's fundamental operation — clamping to valid range

**Max points checklist:**
- [ ] GameStructure class with pure virtual Help()
- [ ] Character inherits from GameStructure, overrides Help()
- [ ] Ninja overrides Help(), Pirate overrides Help()
- [ ] Health getter and setter in Character
- [ ] Setter zeros Health and prints "Character has Expired..." when < 0
- [ ] Two Talk methods (overloading demonstrated)
- [ ] virtual attack() = 10 in Character
- [ ] override attack() = 25 in Ninja and Pirate
- [ ] All lines commented (except cout)
- [ ] Strong UX

---

### Phase 4 — assign_03: Exceptions
**Due:** Jun 4 | **Points:** 40 | **AI Component: Safe Inference Pipeline**

**Rubric breakdown:**
- 10pts: 4+ different exceptions demonstrated, program works as intended, few/no errors
- 5pts: Naming, commenting, readability
- 10pts: Good UX; program description and how-to guide at startup
- 5pts: CSC275-1 — declare variables appropriately
- 10pts: Program does something ADDITIONAL besides demonstrate exceptions
  (⚠ rubric explicitly penalizes if additional functionality is "too similar to requirements")

**Build as:** Model inference engine with layered exception handling.
Five exceptions across different methods (one try/catch block per method — assignment constraint):
1. `InvalidDimensionException` — tensor dimensions incompatible with layer input
2. `UninitializedModelException` — inference called before weights loaded
3. `NumericalInstabilityException` — NaN or Inf detected in layer output
4. `ComputeDeviceException` — GPU unavailable, fallback logic executes
5. `CorruptedWeightException` — checksum failure on weight load (5th for exceptional tier)

Program description and how-to displayed at startup. The inference engine IS the
"additional functionality" — it is the real program; exceptions are safety features
of it, not the purpose of it.

**Max points checklist:**
- [ ] 4+ distinct exception types (5 recommended)
- [ ] Each exception in its own method with exactly one try/catch
- [ ] Multiple catch types used
- [ ] Clear output naming the exception and the condition
- [ ] Program description and how-to guide at startup
- [ ] Inference engine functions independently as a useful tool
- [ ] Additional functionality clearly distinct from just "demo exceptions"
- [ ] All lines commented

---

### Phase 5a — assign_04: File I/O
**Due:** Jun 9 | **Points:** 40 | **AI Component: Weight Serialization / Checkpoint System**

**Rubric breakdown:**
- 10pts: Full understanding of persisting data, few/no errors
- 10pts: Naming, commenting, readability
- 5pts: User-friendly interface with readable output
- 10pts: All submission requirements met (high understanding, few/no errors)
- 5pts: CSC275-1 — declare variables appropriately

**Submission requirements (10pts — don't lose these):**
- YouTube link or screenshot of program performing requirements
- Source code file
- Zip and submit

**Build as:** Model checkpoint system.
- Write layer weights to `checkpoint.txt` while simultaneously displaying to console
- Read checkpoint file and display restored network state
- This IS the mechanism that allows training to pause and resume

**Max points checklist:**
- [ ] Writes to file AND screen at the same time (exact requirement — not separately)
- [ ] Reads from file, displays contents to screen
- [ ] Program description at startup
- [ ] Screenshot or video submitted
- [ ] Source code submitted
- [ ] Zipped and submitted

---

### Phase 5b — assign_04: OOP Project
**Due:** Jun 9 | **Points:** 75 | **AI Component: First Integrated ML Framework Prototype**
**Submission:** Text entry box or file upload (written justification expected)

**Requirements (no separate rubric file found — assignment spec drives grading):**
1. Class Design: 7 classes, clearly defined attributes and behaviors
2. Inheritance: derived from base, provide rationale
3. Polymorphism: overloading or virtual functions, EXPLAIN advantages
4. Encapsulation and Abstraction: access specifiers, JUSTIFY data hiding choices
5. Operator Overloading: EXPLAIN how it enhances usability
6. Exception Handling: implement AND discuss types anticipated
7. File I/O: reading and writing, DISCUSS file format and how it aligns with class design

⚠ This assignment has written justification components ("Explain," "Discuss," "Justify,"
"Provide rationale"). These are likely graded. Prepare written explanations alongside code.

**Seven classes:**
1. `Layer` — abstract base with pure virtual `forward()`
2. `DenseLayer : Layer` — fully connected, concrete `forward()`
3. `ActivationLayer : Layer` — wraps activation function, concrete `forward()`
4. `Model` — owns layers via `vector<unique_ptr<Layer>>`, runs full forward pass
5. `Optimizer` — abstract base with pure virtual `update()`
6. `SGD : Optimizer` — stochastic gradient descent, concrete `update()`
7. `Checkpoint` — file I/O for weight save and restore

Operator overloading: `operator+` on layer outputs for residual connections.
Encapsulation: private weight matrices, public interface only.
Polymorphism: virtual dispatch on mixed layer vector.
Exceptions: guard all allocations and file operations.
File I/O: Checkpoint class (reuse from assign_04a).

**Most important assignment before the final project. Design before coding.**

---

### Phase 6 — assign_05: File I/O with Exception Handling
**Due:** Jun 16 | **Points:** 60 | **AI Component: Robust Training Data Pipeline**

**⚠ RUBRIC DISCREPANCY:** Assignment posted as 60pts. Rubric image totals 40pts.
Investigate with professor before submission — 20 points unaccounted for.

**Rubric breakdown (40pts confirmed):**
- 20pts: Fully working user-friendly install demonstrated in VIDEO (YouTube link required)
- 10pts: All submission requirements met
- 10pts: Fully working detailed user-friendly DOCUMENT created in own words

**⚠ Two deliverables my previous mapping missed:**
1. **YouTube video required** (20pts — the single largest rubric item)
2. **Written user-friendly document** required (10pts) — in your own words, explains the app

**Build as:** Dataset recorder with safe read-back, deployed to a classmate.
- User enters data until "STOP" → lines saved to file
- File read back and displayed → validation
- File not found, permission denied, I/O errors, invalid input → all handled
- UX must be strong enough for classmate deployment

**Submission:**
- YouTube video of working app (20pts — don't skip this)
- Written user-friendly document (10pts)
- Zipped project folder

---

### Phase 7 — assign_06: Pointer Speed and Review
**Due:** Jun 26 | **Points:** 40 | **AI Component: Tensor Operations Library**

**⚠ RUBRIC VALIDATED:** The rubric title is literally
"Computer Sim and Machine Learning Language Rubric."
The professor designed this as an ML simulation assignment.

**Rubric breakdown:**
- 15pts: Application has 5+ functions with const parameter pointers;
  student creates a computer simulation and machine learning language
  that runs and tests with few/no errors (binary — 15 or 0)
- 10pts: Comments, naming, readability
- 10pts: User-friendly interface with good UX
- 5pts: CSC275-1 — declare variables appropriately

**Requirements — must hit exactly:**
- At least 5 functions
- ALL parameters must be const pointers (rubric specifies const)
- Application does something interesting besides demo pointers
- The "something interesting" IS a computer simulation / ML language

**Build as:** Tensor operations library in C-API style (const pointer parameters):
1. `float dot_product(const float* a, const float* b, int* n)`
2. `void relu_forward(const float* input, float* output, int* n)`
3. `void normalize(const float* input, float* output, int* n, const float* mean, const float* std_dev)`
4. `void matrix_multiply(const float* A, const float* B, float* C, int* rows, int* cols, int* inner)`
5. `void softmax(const float* logits, float* probs, int* n)`

This IS the "machine learning language" the rubric describes. BLAS, cuBLAS,
ONNX Runtime — all use exactly this function signature pattern.

**Modern C++ protocol (mastery session, after submission):**
Rewrite using `std::span<const float>` (C++20). Understand when raw const
pointers are the correct tool at hardware boundaries.

**Max points checklist:**
- [ ] 5+ functions, ALL with const pointer parameters
- [ ] Program is a computer simulation / ML language demo (rubric validates this exactly)
- [ ] Runs with few/no errors
- [ ] Fully commented
- [ ] Strong UX
- [ ] Video or screenshots submitted + zipped solution

---

### Phase 8 — assign_08: Allocation and Deallocation
**Due:** Jul 7 | **Points:** 40 | **AI Component: Memory Layout Education + Allocator Foundation**

**⚠ RUBRIC FINDING:** Rubric titled "Smart Pointers Rubric (1)" includes
CSC275-7 "Write memory efficient code through smart pointers" (5pts).
The assignment requires new/delete; the rubric simultaneously requires
smart pointers. Must demonstrate BOTH.

**Rubric breakdown:**
- 15pts: Naming, commenting, readability (LARGEST single criteria — over-comment everything)
- 10pts: User-friendly interface with great UX
- 5pts: CSC275-1 — declare variables appropriately
- 5pts: CSC275-7 — Write memory efficient code through smart pointers
- 5pts: All Assignment Requirements Met in a high-quality manner (binary — 5 or 0)

**Assignment requirements (all 6 required for the 5-pt binary criteria):**
1. Great UX
2. Over comment your code
3. 4 primitive types on heap with new/delete
4. 5 objects with new
5. cout statements explaining allocation/deallocation with examples
6. Program teaches the user about new/delete and memory

**⚠ Submission: Do NOT zip (assignment says "Do not zip these files")**

**Build as:** Narrated walkthrough of neural network memory layout, demonstrating BOTH:

Part A — new/delete (required by assignment, 5pts binary):
- `float*` weight matrix
- `int*` token index array
- `bool*` attention mask
- `double*` gradient buffer
- 5 objects: weight, bias, gradient buffer, index tensor, attention mask
- cout narrates what happens in memory when each allocates and deallocates

Part B — smart pointer equivalent (required by CSC275-7 rubric):
- Same objects rebuilt with unique_ptr
- cout explains why smart pointers eliminate the risks shown in Part A
- This is the "memory efficient code through smart pointers" the rubric grades

**Max points checklist:**
- [ ] 4 primitive types on heap
- [ ] 5 objects created with new
- [ ] All new/delete pairs matched
- [ ] Smart pointer equivalents demonstrated (CSC275-7)
- [ ] cout explains allocation, deallocation, AND smart pointer benefit
- [ ] 15pts worth of comments — over-comment aggressively
- [ ] Source file + YouTube/screenshots submitted (NOT zipped)

---

### Phase 9 — assign_09: Smart Pointers
**Due:** Jul 14 | **Points:** 40 | **AI Component: Neural Network Ownership Model**

**Rubric breakdown:**
- 10pts: Demonstrates pointers going out of scope and values being deleted, few/no errors
- 5pts: Naming, commenting, readability
- 5pts: User-friendly interface with readable output
- 5pts: CSC275-1 — declare variables appropriately
- 5pts: CSC275-7 — Write memory efficient code through smart pointers
- 10pts: Program meets all assignment requirements

**Build as:** Neural network with proper ownership semantics.
- `unique_ptr<Layer>` — exclusive layer ownership inside Model
- `shared_ptr<Weights>` — weight sharing across attention heads (multiple readers, no copy)
- `weak_ptr` — loss monitor watching training state without owning it
- Scope exit demonstrated: Layer destructor fires with cout when pointer goes out of scope
- "Something besides demo": small network running one forward pass; ownership shown as
  a consequence of real computation

**Submission: Do NOT zip (assignment says "Do not zip")**

**Max points checklist:**
- [ ] At least one smart pointer type demonstrated
- [ ] Scope exit demonstrated with cout in destructor
- [ ] Program does something functional beyond demo
- [ ] CSC275-7 satisfied (smart pointer usage throughout)
- [ ] Source files + video/screenshot submitted (NOT zipped)

---

### Phase 10 — assign_10: Direct Recursion
**Due:** Jul 23 | **Points:** 40 | **AI Component: Computation Graph Traversal with Class Hierarchy**

**⚠ RUBRIC FINDING:** Rubric requires CSC275-8 (inheritance/abstract classes, 5pts)
and CSC275-9 (polymorphism, 5pts). The recursion assignment must include a class
hierarchy with abstract base class and polymorphism. This is not optional.

**Rubric breakdown:**
- 5pts: Functional maze using Direct Recursion, different sizes, few/no errors
- 5pts: Naming, commenting, readability
- 5pts: User-friendly interface
- 10pts: All Submission requirements met (LARGEST criteria — binary)
- 5pts: CSC275-1 — declare variables appropriately
- 5pts: CSC275-8 — Derive new classes from base and abstract classes
- 5pts: CSC275-9 — Use polymorphism in applications

**Class hierarchy required for CSC275-8 and CSC275-9:**
- `MazeGenerator` — abstract base class with pure virtual `generate(int rows, int cols)`
- `RecursiveDFS : MazeGenerator` — concrete derived class, implements recursive generation
- Polymorphism: virtual dispatch on MazeGenerator pointer/reference

**⚠ Submission: DO NOT ZIP — submit all source code files unzipped**
**Submit print screen of each maze (two files: 30x30 and 25x25)**
Submission is 10pts (largest criteria) — hitting all submission requirements is critical.

**Maze requirements:**
- Generated from user input (not hardcoded)
- ASCII characters for walls and spaces for paths
- 2D (extra credit for 3D)
- Extra credit for solvable maze (pursue it — BFS/DFS feeds into DSA)

**AI parallel:**
- `MazeGenerator` abstract base → same pattern as abstract `GraphExecutor`
- Recursive maze generation → recursive computation graph construction
- BFS/DFS path-finding (extra credit) → computation graph execution order algorithm
- Backpropagation is graph traversal in reverse — teach this in teach-back

**Max points checklist:**
- [ ] Abstract MazeGenerator base class with pure virtual generate()
- [ ] RecursiveDFS derived class implementing recursive generation
- [ ] Maze generated from user input (not hardcoded)
- [ ] ASCII wall characters and space paths
- [ ] 30x30 and 25x25 both generated and displayed
- [ ] Source files submitted UNZIPPED
- [ ] Print screens of both maze sizes submitted (two files)
- [ ] CSC275-8: class hierarchy with abstract base
- [ ] CSC275-9: polymorphism demonstrated
- [ ] Extra credit: solvable maze via BFS/DFS

---

### Phase 11 — Final Project Checkpoint
**Due:** Jul 28 | **Points:** 30

**Rubric breakdown:**
- 14pts: Source code files present and coherent
- 8pts: 2-3 screenshots of code
- 8pts: README explaining work done and in-progress plan

At checkpoint, the following components should already exist:
- Layer hierarchy with abstract base (assign_01 + 02)
- Safe inference exception handling (assign_03)
- Checkpoint/serialization system (assign_04a)
- Framework prototype with 7 classes (assign_04b)
- Data loader with exception safety (assign_05)
- Tensor ops library (assign_06)
- Ownership model (assign_09)

README explains: how components connect, what is being refined, what
is being added (threading, lambdas, final polish).

---

### Phase 12 — assign_11: Multithreading (Space Race)
**Due:** Aug 4 | **Points:** 30 | **AI Component: Async Training Loop**

**⚠ RUBRIC FINDING:** Rubric includes CSC275-7 "Write memory efficient code
through smart pointers" (5pts). Use smart pointers for managing objects
within the threading code.

**Rubric breakdown:**
- 10pts: Demonstrates creation, execution, and management of multiple threads;
  all assignment requirements met, few/no errors
- 5pts: Naming, commenting, readability
- 5pts: User-friendly interface
- 5pts: CSC275-1 — declare variables appropriately
- 5pts: CSC275-7 — Write memory efficient code through smart pointers

**Space Race requirements — must be exact (rubric checks all):**
- True multithreading (not simulated)
- Main space base launches 10 rockets at Rocket Pad remotely
- 3-second delay between each launch
- After first rocket: transfer launch control to Space Cadet at Rocket Pad
- Abort button at Main Base overrides Space Cadet, stops further launches
- Abort override demonstrated via multithreading
- Over commented
- UX keeps user over-informed at every step
- Smart pointers used for object management (CSC275-7)

**AI parallel:**
- Main thread → Training Coordinator
- Spawn thread → GPU Worker / Data Loader
- 10 rockets → 10 training batches
- 3-second intervals → simulated compute time per batch
- Transfer control → CPU-to-GPU handoff
- Abort override → early stopping signal
- `std::mutex` → protects shared training state
- Thread join → epoch completion before evaluation

**Max points checklist:**
- [ ] True multithreading with std::thread
- [ ] Main thread and at least one spawned thread
- [ ] 10 rockets with 3-second intervals
- [ ] Control transfer after first rocket
- [ ] Abort button halts Space Cadet
- [ ] std::mutex for shared state
- [ ] Thread join demonstrated
- [ ] Smart pointers for object management (CSC275-7)
- [ ] Over-commented
- [ ] Strong UX with step-by-step console narration
- [ ] Source files submitted + screenshots

---

### Phase 13 — Lambda Expressions
**Window:** Aug 4 – Aug 10 | **No Assignment** | **AI Component: Data Pipeline Transforms**

| Topic | AI Application |
|-------|---------------|
| Lambda syntax: capture, parameters, return type | Inline loss functions, custom comparators |
| Capture by value vs reference | Closing over model parameters vs mutable training state |
| Lambdas as STL algorithm arguments | `std::transform` for normalization, `std::sort` for ranked results |
| `std::function` and type-erasure | Storing callable pipeline stages |
| Lambdas in multithreaded contexts | Thread pool tasks; capturing `shared_ptr` to extend lifetime |

---

### Phase 14 — Final Project: Lightweight NN Inference Engine
**Due:** Aug 17 | **Points:** 150 | **Boards candidate**

**Rubric breakdown:**
- 80pts: Innovative application, fully functional, all requirements met
  (excluding max 5 opt-outs), very few/no errors
- 35pts: Naming, commenting, maintainable code, consistently formatted
- 25pts: Great UX — enjoyable overall experience, UI friendly and easy,
  readable output without issues
- 10pts: CSC275-1 — declare variables appropriately

**Decision made May 9, 2026. Not revisiting.**

Required features (opt out max 5 — choose deliberately):
- Opening screen + instructions
- Menu for user options
- 4+ classes (Layer, Model, Optimizer, Checkpoint minimum)
- Inheritance (DenseLayer, ActivationLayer, SGD)
- Polymorphism (virtual forward, overloaded compute)
- Encapsulation (private weights)
- File I/O (Checkpoint system)
- Multi-threading (async data loading or inference worker)
- Templates (typed containers, generic pipeline)
- Vectors (dataset, layer registry)
- Iterators (batch iteration)
- Recursion (graph traversal)
- Exception handling (safe inference pipeline)
- Abstraction (pure virtual interfaces)
- Lambdas (pipeline transforms)

**External review target:** Show to Ben or Kelly before final submission.

---

## Course Point Summary

| Assignment | Due | Points | AI Component | Submission |
|-----------|-----|--------|--------------|-----------|
| assign_01 OOP I | May 19 | 40 | Layer architecture pattern | Zip + source + screenshot |
| assign_02 OOP II | May 26 | 25 | Abstract interface pattern | Zip + source + screenshot |
| assign_03 Exceptions | Jun 4 | 40 | Safe inference pipeline | Zip + source + screenshot |
| assign_04 File I/O | Jun 9 | 40 | Weight serialization | Screenshot + source + zip |
| assign_04 OOP Project | Jun 9 | 75 | Framework prototype | Text entry or file upload |
| assign_05 File I/O + Exceptions | Jun 16 | 60* | Robust data loader | **VIDEO** + doc + zip |
| assign_06 Pointer Speed | Jun 26 | 40 | Tensor ops library (ML rubric!) | Video/screenshot + zip |
| assign_08 Allocation | Jul 7 | 40 | Memory layout + smart ptr | Source + video — **NO ZIP** |
| assign_09 Smart Pointers | Jul 14 | 40 | Ownership model | Source + video — **NO ZIP** |
| assign_10 Recursion | Jul 23 | 40 | Graph traversal w/ classes | Source + 2 screenshots — **NO ZIP** |
| Final Project Checkpoint | Jul 28 | 30 | Integration status | Source + screenshots + README |
| assign_11 Multithreading | Aug 4 | 30 | Async training loop | Source + screenshots |
| Lambda (no assignment) | Aug 4-10 | — | Pipeline transforms | — |
| Final Project | Aug 17 | 150 | Complete system | Source + zip |
| Discussions (20%) + Quizzes (15%) | ongoing | — | — | — |

*assign_05: 60pts posted, 40pts in rubric — investigate with professor

**⚠ Submission format varies by assignment — zip vs no-zip. Check before submitting.**

---

## Topics Completed
| Topic | Date | Bloom Level | Notes |
|-------|------|-------------|-------|
| Stack vs Heap (conceptual) | 2026-05-08 | 2 – Understand | Can explain ownership distinction, cafeteria tray analogy internalized |
| Raw pointer failure modes | 2026-05-08 | 2 – Understand | Named and explained all 3: leak, double-delete, use-after-delete. Correct in own words. |
| RAII concept | 2026-05-08 | 2 – Understand | Can explain the pattern. Corrected Allocation→Acquisition. Needs more reps to hit Apply. |
| Constructors and Destructors | 2026-05-08 | 2 – Understand | Demonstrated via scope_demo. Knows destructor fires at closing brace, not at use-end. |
| std::unique_ptr (intro) | 2026-05-08 | 2 – Understand | Can explain mechanism: destructor calls delete automatically. Typed working code. |

## Diagnostic Findings (Session 1)
- Completed UAT C++ Course I: 15 topics, 1 week each, surface level only
- Cannot defend any concept without looking it up — confirmed by Q1–Q5 audit
- Loops flagged as shaky — address in upcoming session, connect to algorithm work
- Brace initialization used correctly by instinct — reinforce why it's preferred
- Strong self-awareness: self-identified the constructor/destructor gap mid-session

## Current Blockers
- Constructor/destructor not fully automatic yet — needs more reps
- RAII chain solid conceptually but not at Apply level — needs independent practice next session
- Loops (when to use which): flagged, not yet addressed

## Wins
- Typed all code independently, no copy-paste
- Diagnosed own linker error correctly (two main() functions)
- Diagnosed own compile error correctly (Resource class not in scope)
- Delivered honest Q1–Q5 audit — no overselling
- Strong paragraph summary at session close, own words
- Mapped full course to NN inference engine architecture — 2026-05-09
- Committed to final project domain before checkpoint — 2026-05-09
- Full rubric audit completed — mapping verified and corrected — 2026-05-09

## Dysregulation Events
None this session.

## Retrieval Queue
| Question | Assigned | Answer Due | Status |
|----------|----------|------------|--------|
| A function allocates heap memory with `new`, runs logic, then throws an exception before reaching `delete`. What happens with a raw pointer? What happens with `unique_ptr`? Why? | 2026-05-08 | 2026-05-09 | Pending |
