# General Writing Guidelines

## What should be covered?

For embedded systems requirements typically define:

- System behavior
- Timing constraints
- Hardware interaction
- Error handling
- Resource limitations
- Public C Interface (API)

They should describe what the software does, not how it does it.

The document should be structured like the this:

1. Introduction
2. System Overview
3. Functional Requirements
4. Non-functional Requirements
5. Hardware Interface Requirements
6. Public C API Specifications
7. Constraints
8. Verification Strategy

## Writing Principles

Requirements should be:

- Clear and unambiguous
- Measurable
- Testable
- Aware of hardware constraints
- Free from implementation details

## Avoid Ambiguity

Avoid using vague or subject terms such as:

- fast
- lightweight
- efficient
- stable
If performance or quality attributes are required, they should be expressed using measurable criteria.
