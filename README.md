AI Service Token Management System
A robust C++ Console Application designed to manage user accounts and token-based access to tiered AI services. This system simulates a commercial environment where users (Trial, Full, or Standard) can purchase tokens and consume them across various AI-driven tasks.

🚀 Key Features
User Management: Supports loading, sorting, editing, and deleting user records.

Tiered Service Access: Implements different logic and limitations for Trial, Full, and Standard accounts.

AI Service Simulation:

Image Recognition (pricing based on file size).

Speech-to-Text Transcription (pricing based on duration).

Predictive Analysis.

Natural Language Processing (NLP).

Financial Logic: Automated top-up system and transaction history tracking.

🛠️ Technical Stack
Language: C++

Concepts: Object-Oriented Programming (OOP), Data Encapsulation, File Simulation, Array/Vector Management.

Libraries: <iostream>, <vector>, <iomanip> (for formatted reporting), <string>.

💻 My Contributions
As a core developer in this group project, I was responsible for the Administrative and System Analytics layer of the application. My primary work included:

1. System Usage Summary (Analytics Module)
I engineered the systemUsageSummary function to provide administrators with a high-level overview of system performance.

Data Aggregation: Developed logic to sum up token consumption across all four AI service categories.

Financial Reporting: Tracked total revenue generated from manual purchases and automated top-up triggers.

Data Visualization: Utilized the iomanip library to create a structured, professional table layout for real-time reporting.

2. Administrative Flow & Termination
I designed the creditAndExit module to manage the application's lifecycle.

Confirmation Logic: Implemented a recursive/loop-based confirmation flow to prevent accidental system shutdowns.

Team Documentation: Created a formatted credits display to identify contributors and student credentials.
