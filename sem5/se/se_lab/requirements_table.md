# **Problem Statement 29 Municipal Infrastructure Damage Reporting App**
### Name : Dharani S
### SRN: PES2UG24CS157
### Section: C
**Domain:** Smart Cities, Transport & Logistics
**Actors:** Citizen Reporter, Municipal Engineer


## Functional Requirements

| ID | Type | Description | Priority | Acceptance Criteria | Rationale |
|----|------|-------------|----------|----------------------|-----------|
| FR-001 | Functional – Geolocation | The system shall extract EXIF GPS metadata from uploaded damage photos to automatically pinpoint the incident location on the municipal GIS map. | High | **Pass:** Pothole report routed to Road Infrastructure division with exact GPS coordinates. **Fail:** Report submitted without location data. | Location accuracy is the single most important input for correct department dispatch and field-crew navigation. |
| FR-002 | Functional – Data Capture | The system shall allow a Citizen Reporter to submit a damage report by selecting a category (Pothole, Streetlight, Water Leak), attaching up to 3 photos, and adding an optional text description. | High | **Pass:** Report is saved with category, photo(s), timestamp, and citizen ID attached. **Fail:** Report accepted without a selected category. | Structured categorisation is required before automated routing (FR-003) can function. |
| FR-003 | Functional – Workflow / Routing | The system shall automatically dispatch a newly created ticket to the correct municipal engineering division based on the report category and GPS zone, and generate a unique ticket ID. | High | **Pass:** A "Streetlight" report is auto-assigned to the Electrical Maintenance division within 60 seconds of submission. **Fail:** Ticket remains unassigned after 5 minutes. | Manual triage causes delays; automated routing is the core value proposition of the app. |
| FR-004 | Functional – Tracking / Notification | The system shall allow a Citizen Reporter to view real-time ticket status (Submitted → Acknowledged → In Progress → Resolved) and receive a push/SMS notification on every status change. | Medium | **Pass:** Citizen receives a notification within 2 minutes of the Municipal Engineer updating ticket status. **Fail:** Status change occurs with no citizen-facing notification. | Transparency increases citizen trust and reduces duplicate/repeat reporting of the same issue. |
| FR-005 | Functional – Ticket Management | The system shall provide a Municipal Engineer dashboard to view all tickets assigned to their division, filter by status/priority/location, update ticket status, and upload resolution proof photos before closing a ticket. | Medium | **Pass:** Engineer closes a ticket only after attaching at least one "after" photo. **Fail:** Ticket can be marked Resolved with zero attachments. | Photographic proof of resolution is required for municipal audit and citizen accountability. |

<div class="page-break"></div>

## Non-Functional Requirements

| ID | Type | Description | Priority | Acceptance Criteria | Rationale |
|----|------|-------------|----------|----------------------|-----------|
| NFR-001 | Performance & Security | The reporting portal shall support offline report drafting and auto-sync when mobile network connectivity resumes; all synced data shall be transmitted over TLS 1.2+. | High | **Pass:** Benchmarking tests confirm target latency (sync completes within 10s of reconnect) and TLS encryption on all API calls under simulated peak load. **Fail:** Draft data lost on connectivity drop, or data transmitted unencrypted. | Field connectivity in low-infrastructure areas (where damage is most common) is unreliable, and location/photo data is sensitive. |
| NFR-002 | Usability & Accessibility | The citizen-facing app shall support at least 2 regional languages (in addition to English) and provide voice-assisted report submission for low-literacy users. | Medium | **Pass:** A user can complete a full report submission using only voice prompts in the selected regional language. **Fail:** App is unusable without English text input. | Municipal citizen bases are linguistically diverse; accessibility directly affects civic-tech adoption rates. |

