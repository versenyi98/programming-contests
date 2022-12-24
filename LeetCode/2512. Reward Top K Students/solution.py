class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str],
                    student_id: List[int], k: int) -> List[int]:
        positive_feedback = set(positive_feedback)
        negative_feedback = set(negative_feedback)

        points = {id: (0, id) for id in student_id}

        for idx, rep in enumerate(report):
            current_points = points[student_id[idx]]

            for word in rep.split():
                if word in negative_feedback:
                    current_points = (current_points[0] - 1, current_points[1])
                if word in positive_feedback:
                    current_points = (current_points[0] + 3, current_points[1])
            points[student_id[idx]] = current_points

        results = sorted(points.values(), key=lambda x: (-x[0], x[1]))[:k]

        return list(map(lambda x: x[1], results))